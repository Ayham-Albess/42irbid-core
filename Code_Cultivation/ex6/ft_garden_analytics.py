class Plant:
    def __init__(self, name: str, height: int, age: int):
        self.__name = name
        self.__height = 0
        self.__age = 0

        if height >= 0:
            self.__height = height
        if age >= 0:
            self.__age = age

    def set_height(self, height: int) -> None:
        if height < 0:
            print(f"Invalid operation attempted: height {height}cm [REJECTED]")
            print("Security: Negative height rejected\n")
        else:
            self.__height = height

    def set_age(self, age: int) -> None:
        if age < 0:
            print(f"Invalid operation attempted: age {age} days [REJECTED]")
            print("Security: Negative age rejected\n")
        else:
            self.__age = age

    def grow(self) -> None:
        self.__height += 1

    def base_info(self) -> str:
        return f"{self.get_height()}cm, {self.get_age()} days"

    def get_name(self) -> str:
        return self.__name

    def get_age(self) -> int:
        return self.__age

    def get_height(self) -> int:
        return self.__height


class FloweringPlant(Plant):
    def __init__(self, name: str, height: int, age: int, flower_color: str):
        super().__init__(name, height, age)
        self.__flower_color = flower_color

    def bloom(self) -> None:
        print(f"{self.get_name()} is blooming beautifully!\n")

    def get_color(self) -> str:
        return self.__flower_color

    def get_info(self) -> str:
        return (
                f"{self.get_name()} (FloweringPlant):  {self.base_info()}, "
                f"{self.__flower_color} color"
                )


class PrizeFlower(FloweringPlant):
    def __init__(self, name: str, height: int, age: int, flower_color: str, prize_points: int):
        super().__init__(name, height, age, flower_color)
        self.__prize_points = prize_points

    def get_prize_points(self) -> int:
        return self.__prize_points

    def get_info(self) -> str:
        return (
                f"{self.get_name()} (PrizeFlower):  {self.base_info()}, "
                f"{self.get_color()} color {self.get_prize_points()} prize_points"
                )

class Garden()
