def garden_operations(operation_number: int) -> None:
    print(f"Testing operation {operation_number}...")
    match(operation_number):
        case 0:
            int("abc")
        case 1:
            1 / 0
        case 2:
            open("/non/existent/file")
        case 3:
            "abc" + 10
        case _:
            return


def test_error_types():
    print("=== Garden Error Types Demo ===")
    for i in range(5):
        try:
            garden_operations(i)
        except (
            ValueError, ZeroDivisionError,
            FileNotFoundError, TypeError,
        ) as error:
            print(f"Cought {error.__class__.__name__}: {error}")


if __name__ == "__main__":
    test_error_types()
    print()
    print("All error types tested successfully!")
