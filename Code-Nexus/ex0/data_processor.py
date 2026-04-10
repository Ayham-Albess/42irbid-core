from typing import Any
from abc import ABC, abstractmethod


class DataProcessor (ABC):
    def __init__(self) -> None:
        self.values: list[tuple[int, str]] = []
        self.index = 0

    @abstractmethod
    def validate(self, data: Any) -> bool:
        pass

    @abstractmethod
    def ingest(self, data: Any) -> None:
        pass

    def output(self) -> tuple[int, str]:
        if self.values:
            return self.values.pop(0)
        else:
            raise IndexError("There is not any values")


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
            else:
                self.values.append((self.index, str(data)))
                self.index += 1
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
            else:
                self.values.append((self.index, data))
                self.index += 1
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
            else:
                self.values.append(
                        (self.index, ":".join([str(x) for x in data.values()]))
                        )
                self.index += 1
        else:
            raise TypeError("Got exception: Improper dict data")


print("=== Code Nexus - Data Processor ===")
print("Testing Numeric Processor...")
N_processor: NumericProcessor = NumericProcessor()
print(f"Trying to validate input ’42’: {N_processor.validate(42)}")
print(f"Trying to validate input ’Hello’: {N_processor.validate("Hello")}")
print("Test invalid ingestion of string ’foo’ without prior validation:")
try:
    N_processor.ingest("foo")  # type:ignore
except TypeError as e:
    print(e)
print("Processing data: [1, 2, 3, 4, 5]")
try:
    N_processor.ingest([1, 2, 3, 4, 5])
except TypeError as e:
    print(e)
try:
    print("Extracting 3 values...")
    for i in range(3):
        i1, i2 = N_processor.output()
        print(f"Numeric value {i1}: {i2}")
except IndexError as e:
    print(e)
print("\nTesting Text Processor...")
T_processor: TextProcessor = TextProcessor()
print(f"Trying to validate input ’Rashed’: {T_processor.validate("Rashed")}")
print(f"Trying to validate input ’42’: {T_processor.validate(42)}")
print("Test invalid ingestion of int ’42’ without prior validation:")
try:
    T_processor.ingest(42)  # type:ignore
except TypeError as e:
    print(e)
print("Processing data: [’Hello’, ’Nexus’, ’World’]")
try:
    T_processor.ingest(["Hello", "Nexus", "World"])
except TypeError as e:
    print(e)
try:
    print("Extracting 1 value...")
    for i in range(1):
        i1, i2 = T_processor.output()
        print(f"Text value {i1}: {i2}")
except IndexError as e:
    print(e)
print("\nTesting Log Processor...")
L_processor: LogProcessor = LogProcessor()
print("Trying to validate input ’{’log_level’: ’NOTICE’}’:", end=" ")
print(L_processor.validate({"log_level": "NOTICE"}))
print(f"Trying to validate input ’42’: {L_processor.validate(42)}")
print("Test invalid ingestion of string ’Test’ without prior validation:")
try:
    L_processor.ingest("Test")  # type:ignore
except TypeError as e:
    print(e)
print("Processing data: [{’log_level’: ’NOTICE’, ’log_message’: "
      "’Connection to server’}, {’log_level’: ’ERROR’, ’log_message’: "
      "’Unauthorized access!!’}]")
try:
    L_processor.ingest([
                {"log_level": "NOTICE", "log_message": "Connection to server"},
                {"log_level": "ERROR", "log_message": "’Unauthorized access!!"}
                ])
    print("Extracting 2 values...")
    for i in range(2):
        i1, i2 = L_processor.output()
        print(f"Log entry {i1}: {i2}")
except (IndexError, TypeError) as e:
    print(e)
