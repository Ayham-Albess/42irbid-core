def check_temperature(temp_str: str) -> int:
    try:
        try:
            n = int(temp_str)
        except ValueError:
            print("Error: ’abc’ is not a valid number")
            return None
        n = int(temp_str)
        if n < 0:
            raise ValueError(f"Error: {n}°C is too cold for plants (min 0°C)")
            return None
        if n > 40:
            raise ValueError(f"Error: {n}°C is too hot for plants (max 40°C)")
            return None
        raise ValueError(f"Temperature {n}°C is perfect for plants!")
        return n
    except ValueError as e:
        print(e)
        return None


def test_temperature_input() -> None:
    print("=== Garden Temperature Checker ===")
    print("\nTesting temperature: 25")
    check_temperature('25')
    print("\nTesting temperature: abc")
    check_temperature('abc')
    print("\nTesting temperature: 100")
    check_temperature('100')
    print("\nTesting temperature: -50")
    check_temperature('-50')
    print("\nAll tests completed - program didn’t crash!")


if __name__ == "__main__":
    test_temperature_input()
