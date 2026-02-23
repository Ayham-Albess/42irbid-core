class Plant:
    def __init__(self, name: str, Height: int, age: int):
        self.__name = name
        self.__name = self.__name.capitalize()
        self.__Height = Height
        self.__age = age

    def print_info(self):
        print(f"{self.__name}:  {self.__Height}cm, {self.__age} days old")


if __name__ == "__main__":
    p1 = Plant("rose", 25, 30)
    p2 = Plant("Sunflower", 80, 45)
    p3 = Plant("Cactus", 15, 120)
    print("=== Garden Plant Registry ===")
    p1.print_info()
    p2.print_info()
    p3.print_info()
