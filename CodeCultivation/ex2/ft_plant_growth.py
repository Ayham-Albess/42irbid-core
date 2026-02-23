class Plant:
    def __init__(self, name: str, Height: int, age: int):
        self.__name = name
        self.__name = self.__name.capitalize()
        self.__Height = Height
        self.__age = age
        self.__base_age = self.__age
        self.__base_Height = self.__Height

    def grow(self) -> None:
        self.__Height += 1

    def age(self) -> None:
        self.__age += 1

    def get_info(self, days: int) -> None:
        for i in range(days):
            self.grow()
            self.age()
        self.print_info()
        if self.__Height != self.__base_Height:
            dif = self.__Height - self.__base_Height
            print(f"Growth this week:  +{dif}cm")

    def print_info(self) -> None:
        print(f"{self.__name}:  {self.__Height}cm, {self.__age} days old")


if __name__ == "__main__":
    p1 = Plant("rose", 25, 30)
    p2 = Plant("Sunflower", 80, 45)
    p3 = Plant("Cactus", 15, 120)
    print("=== Day 1 ===")
    p1.get_info(0)
    print("=== Day 7 ===")
    p1.get_info(6)
