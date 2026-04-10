from typing import Any, Protocol
from abc import ABC, abstractmethod


class ExportPlugin (Protocol):
    def process_output(self, data: list[tuple[int, str]]) -> None:
        ...


class CSV:
    def process_output(self, data: list[tuple[int, str]]) -> None:
        if data != []:
            print("CSV Output:")
            print(",".join(i[1] for i in data))


class JSON:
    def process_output(self, data: list[tuple[int, str]]) -> None:
        if data != []:
            print("JSON Output:", end="\n{")
            for i in data:
                if data.index(i) == len(data) - 1:
                    print(f"item_{i[0]}: \"{i[1]}\"", end="")
                else:
                    print(f"item_{i[0]}: \"{i[1]}\"", end=", ")
            print("}")


class DataProcessor (ABC):
    def __init__(self) -> None:
        self.values: list[tuple[int, str]] = []
        self.index = 0
        self.total = 0
        self.__name = ""

    @abstractmethod
    def validate(self, data: Any) -> bool:
        pass

    @abstractmethod
    def ingest(self, data: Any) -> None:
        pass

    def output(self) -> tuple[int, str]:
        if self.values:
            self.total -= 1
            return self.values.pop(0)
        else:
            raise IndexError("There is not any values")

    def get_name(self):
        return self.__name

    def set_name(self, n: str):
        self.__name = n


class NumericProcessor(DataProcessor):
    def validate(self, data: Any) -> bool:
        if (isinstance(data, (int, float)) or
           (isinstance(data, list) and
           all(isinstance(x, (int, float)) for x in data))):
            return True
        return False

    def ingest(self, data: int | float | list[int | float]) -> None:
        if self.validate(data):
            if isinstance(data, list):
                for i in data:
                    self.values.append((self.index, str(i)))
                    self.index += 1
                    self.total += 1
            else:
                self.values.append((self.index, str(data)))
                self.index += 1
                self.total += 1
        else:
            raise TypeError("Got exception: Improper numeric data")


class TextProcessor (DataProcessor):
    def validate(self, data: Any) -> bool:
        if (isinstance(data, str) or
           (isinstance(data, list) and
                all(isinstance(x, str) for x in data))):
            return True
        return False

    def ingest(self, data: str | list[str]) -> None:
        if self.validate(data):
            if isinstance(data, list):
                for i in data:
                    self.values.append((self.index, i))
                    self.index += 1
                    self.total += 1
            else:
                self.values.append((self.index, data))
                self.index += 1
                self.total += 1
        else:
            raise TypeError("Got exception: Improper string data")


class LogProcessor (DataProcessor):
    def validate(self, data: Any) -> bool:
        if isinstance(data, list):
            for x in data:
                if isinstance(x, dict):
                    for i in x.keys():
                        if not isinstance(i, str):
                            return False
                    for i in x.values():
                        if not isinstance(i, str):
                            return False
                else:
                    return False
            return True
        elif isinstance(data, dict):
            for i in data.keys():
                if not isinstance(i, str):
                    return False
            for i in data.values():
                if not isinstance(i, str):
                    return False
            return True
        return False

    def ingest(self, data: dict[str, str] | list[dict[str, str]]) -> None:
        if self.validate(data):
            if isinstance(data, list):
                for i in data:
                    self.values.append(
                        (self.index, ": ".join([str(x) for x in i.values()]))
                        )
                    self.index += 1
                    self.total += 1
            else:
                self.values.append(
                        (self.index, ":".join([str(x) for x in data.values()]))
                        )
                self.index += 1
                self.total += 1
        else:
            raise TypeError("Got exception: Improper dict data")


class DataStream:
    def __init__(self) -> None:
        self.Processores: list[DataProcessor] = []

    def register_processor(self, proc: DataProcessor) -> None:
        print(f"Registering {proc.get_name()}")
        self.Processores.append(proc)

    def process_stream(self, stream: list[Any]) -> None:
        for data in stream:
            handled = False
            for proc in self.Processores:
                if proc.validate(data):
                    proc.ingest(data)
                    handled = True
                    break
            if not handled:
                print("DataStream error - "
                      f"Can’t process element in stream: {data}")

    def print_processors_stats(self) -> None:
        print("== DataStream statistics ==")
        if not len(self.Processores):
            print("No processor found, no data")
        else:
            for proc in self.Processores:
                print(f"{proc.get_name()}: total {proc.index} items processed,"
                      f" remaining {proc.total} on processor")

    def output_pipeline(self, nb: int, plugin: ExportPlugin) -> None:
        temp: list[tuple[int, str]] = []

        p_n = plugin.__class__.__name__
        print(f"Send {nb} processed data from"
              f" each processor to a {p_n} plugin:")
        for i in self.Processores:
            temp = []
            for z in range(nb):
                try:
                    temp.append(i.output())
                except IndexError:
                    plugin.process_output(temp)
                    temp = []
                    break
            plugin.process_output(temp)


print("=== Code Nexus - Data Pipeline ===")
print("\nInitialize Data Stream...\n")
data_stream: DataStream = DataStream()
data_stream.print_processors_stats()
print()
n_proc: NumericProcessor = NumericProcessor()
n_proc.set_name("Numeric Processor")
t_pros: TextProcessor = TextProcessor()
t_pros.set_name("Text Processor")
data_stream.register_processor(t_pros)
l_pros: LogProcessor = LogProcessor()
l_pros.set_name("Log Processor")
data_stream.register_processor(l_pros)
data_stream.register_processor(n_proc)
print("\nSend first batch of data on stream: [’Hello world’, [3.14, -1,2.71],"
      " [{’log_level’: ’WARNING’, ’log_message’: ’Telnet access! Use"
      " ssh instead’}, {’log_level’: ’INFO’, ’log_message’: ’User wil"
      " is connected’}], 42, [’Hi’, ’five’]]\n")
data_stream.process_stream([
    "Hello world",
    [3.14, -1, 2.71],
    [
        {"log_level": "WARNING",
         "log_message": "Telnet access! Use ssh instead"},
        {"log_level": "INFO", "log_message": "User wil is connected"}
    ],
    42,
    ["Hi", "five"]
])
data_stream.print_processors_stats()
print()
csv: CSV = CSV()
data_stream.output_pipeline(3, csv)
print()
data_stream.print_processors_stats()
print("\nSend another batch of data: [21, [’I love AI’, ’LLMs are"
      "wonderful’, ’Stay healthy’], [{’log_level’: ’ERROR’, ’log_message’: "
      "’500 server crash’}, {’log_level’: ’NOTICE’, ’log_message’: "
      "’Certificate expires in 10 days’}], [32, 42, 64, 84, 128, 168],"
      "’World hello’]\n")
data_stream.process_stream([
    21,
    ["I love AI", "LLMs are wonderful", "Stay healthy"],
    [
        {"log_level": "ERROR", "log_message": "500 server crash"},
        {"log_level": "NOTICE", "log_message": "Certificat expires in 10 days"}
    ],
    [32, 42, 64, 84, 128, 168],
    "World hello"
])
data_stream.print_processors_stats()
print()
json: JSON = JSON()
data_stream.output_pipeline(5, json)
print()
data_stream.print_processors_stats()
