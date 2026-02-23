class Plant:
    def __init__(self, name: str, height: int, age: int):
        self.__name = name

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

    def base_info(self) -> str:
        return f"{self.get_height()}cm, {self.get_age()} days"

    def get_name(self) -> str:
        return self.__name

    def get_age(self) -> int:
        return self.__age

    def get_height(self) -> int:
        return self.__height


class Tree(Plant):
    def __init__(self, name, height, age, trunk_diameter):
        self.__trunk_diameter = trunk_diameter
        super().__init__(name, height, age)

    def get_info(self) -> str:
        return (
                f"{self.get_name()} (Tree):  {self.base_info()}, "
                f"{self.__trunk_diameter}cm diameter"
                )

    def produce_shade(self) -> None:
        shade_area = self.get_height() * self.__trunk_diameter * 0.00312
        print(f"{self.get_name()} provides {shade_area:.0f}", end=' ')
        print("square meters of shade\n")


class Flower(Plant):
    def __init__(self, name, height, age, color):
        self.__color = color
        super().__init__(name, height, age)

    def get_info(self) -> str:
        return (
                f"{self.get_name()} (Flower):  {self.base_info()}, "
                f"{self.__color} color"
                )

    def bloom(self) -> None:
        print(f"{self.get_name()} is blooming beautifully!\n")


class Vegetable(Plant):
    def __init__(self, name, height, age, harvest_season, nutritional_value):
        self.__harvest_season = harvest_season
        self.__nutritional_value = nutritional_value
        super().__init__(name, height, age)

    def get_info(self) -> str:
        return (
                f"{self.get_name()} (Vegetable):  {self.base_info()}, "
                f"{self.__harvest_season} harvest"
                )

    def nutrition_info(self) -> None:
        print(f"{self.get_name()} is rich in {self.__nutritional_value}\n")


if __name__ == "__main__":
    print("=== Garden Plant Types ===\n")

    rose = Flower("Rose", 25, 30, "red")
    oak = Tree("Oak", 500, 1825, 50)
    tomato = Vegetable("Tomato", 80, 90, "summer", "vitamin C")

    print(rose.get_info())
    rose.bloom()

    print(oak.get_info())
    oak.produce_shade()

    print(tomato.get_info())
    tomato.nutrition_info()
