class GardenError(Exception):
    pass


class PlantError(GardenError):
    pass


class WaterError(GardenError):
    pass


class GardenManager:
    def __init__(self) -> None:
        self.plants: list[str] = []

    def add_plant(self, plant_name: str) -> None:
        if plant_name == "":
            raise PlantError("Plant name cannot be empty!")
        self.plants += [plant_name]
        print(f"Added {plant_name} successfully")

    def water_plants(self) -> None:
        print("Opening watering system")
        try:
            if self.plants == []:
                raise WaterError("No plants to water")

            for plant in self.plants:
                if plant is None:
                    raise PlantError("Invalid plant in list")
                print(f"Watering {plant} - success")

        except PlantError as e:
            print(f"Error watering plant: {e}")
        finally:
            print("Closing watering system (cleanup)\n")

    def check_plant_health(
        self,
        plant_name: str,
        water_level: int,
        sunlight_hours: int
    ) -> None:

        if plant_name == "":
            raise ValueError("Plant name cannot be empty!")

        if water_level < 1:
            raise ValueError(
                f"Water level {water_level} is too low (min 1)"
            )

        if water_level > 10:
            raise ValueError(
                f"Water level {water_level} is too high (max 10)"
            )

        if sunlight_hours < 2:
            raise ValueError(
                f"Sunlight hours {sunlight_hours} is too low (min 2)"
            )

        if sunlight_hours > 12:
            raise ValueError(
                f"Sunlight hours {sunlight_hours} is too high (max 12)"
            )

        print(
            f"{plant_name}: healthy "
            f"(water: {water_level}, sun: {sunlight_hours})"
        )


def test_garden_management() -> None:
    print("=== Garden Management System ===\n")

    M = GardenManager()

    print("Adding plants to garden...")

    try:
        M.add_plant("tomato")
        M.add_plant("lettuce")
        M.add_plant("")
    except PlantError as e:
        print(f"Error adding plant: {e}\n")

    print("Watering plants...")
    M.water_plants()

    print("Checking plant health...")

    try:
        M.check_plant_health("tomato", 5, 8)
    except ValueError as e:
        print(f"Error checking tomato: {e}")

    try:
        M.check_plant_health("lettuce", 15, 8)
    except ValueError as e:
        print(f"Error checking lettuce: {e}\n")

    print("Testing error recovery...")

    try:
        raise WaterError("Not enough water in tank")
    except GardenError as e:
        print(f"Caught GardenError: {e}")
        print("System recovered and continuing...\n")

    print("Garden management system test complete!")


if __name__ == "__main__":
    test_garden_management()
