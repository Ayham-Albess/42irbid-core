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
            print(f"Height updated: {height}cm [OK]")

    def set_age(self, age: int) -> None:
        if age < 0:
            print(f"Invalid operation attempted: age {age} days [REJECTED]")
            print("Security: Negative age rejected\n")
        else:
            self.__age = age
            print(f"Age updated: {age} days [OK]\n")

    def get_info(self) -> str:
        return f"{self.__name} ({self.__height}cm, {self.__age} days)"


if __name__ == "__main__":
    print("=== Garden Security System ===")

    plant = Plant("Rose", 25, 30)
    print("Plant created: Rose")

    plant.set_height(25)
    plant.set_age(30)

    plant.set_height(-5)
    plant.set_age(-1)

    print(f"Current plant: {plant.get_info()}")
