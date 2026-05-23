def input_temperature(temp_str: str):
    print(f"Input data is '{temp_str}'")
    temp_int = int(temp_str)
    return temp_int


def test_temperature():
    print("=== Garden Temperature ===")
    print()
    try:
        temp = "25"
        temperature_int = input_temperature(temp)
        print(f"Temperature is now {temperature_int}°C")
        print()
        temp = "abc"
        temperature_int = input_temperature(temp)
        print(f"Temperature is now {temperature_int}°C")
    except ValueError as error:
        print(f"Caught input_temperature error: {error}")


if __name__ == "__main__":
    test_temperature()
    print()
    print("All tests completed - program didn't crash!")
