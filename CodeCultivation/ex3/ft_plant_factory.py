class Plant:
    def __init__(self, name: str, height: int, age: int):
        self.__name = name
        self.__height = height
        self.__age = age

    def get_info(self) -> str:
        return f"{self.__name} ({self.__height}cm, {self.__age} days)"


if __name__ == "__main__":
    print("=== Plant Factory Output ===")

    plant_data = [
        ("Rose", 25, 30),
        ("Oak", 200, 365),
        ("Cactus", 5, 90),
        ("Sunflower", 80, 45),
        ("Fern", 15, 120),
    ]

    plants = []
    count = 0
    for name, height, age in plant_data:
        plant = Plant(name, height, age)
        plants.append(plant)
        count += 1
        print(f"Created:  {plant.get_info()}")

    print(f"\nTotal plants created:  {count}")
