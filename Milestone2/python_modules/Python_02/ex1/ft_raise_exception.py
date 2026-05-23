def input_temperature(temp_str: str):
    print(f"Input data is '{temp_str}'")
    temp_int = int(temp_str)
    if temp_int > 40:
        raise ValueError(f"{temp_int}°C is too hot for plants (max 40°C)")
    elif temp_int < 0:
        raise ValueError(f"{temp_int}°C is too cold for plants (min 0°C)")
    return temp_int


def test_temperature():
    print("=== Garden Temperature Checker ===")
    print()
    try:
        temp = "25"
        temperature_int = input_temperature(temp)
        print(f"Temperature is now {temperature_int}°C")
        print()
    except ValueError as error:
        print(f"Caught input_temperature error: {error}")

    try:
        temp = "abc"
        temperature_int = input_temperature(temp)
        print(f"Temperature is now {temperature_int}°C")
    except ValueError as error:
        print(f"Caught input_temperature error: {error}")
        print()

    try:
        temp = "100"
        temperature_int = input_temperature(temp)
        print(f"Temperature is now {temperature_int}°C")
        print()
    except ValueError as error:
        print(f"Caught input_temperature error: {error}")
        print()

    try:
        temp = "-50"
        temperature_int = input_temperature(temp)
        print(f"Temperature is now {temperature_int}°C")
    except ValueError as error:
        print(f"Caught input_temperature error: {error}")
        print()


if __name__ == "__main__":
    test_temperature()
    print("All tests completed - program didn't crash!")
