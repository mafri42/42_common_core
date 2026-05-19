class GardenError(Exception):
    def __init__(self, message: str = "Unknown plant error") -> None:
        super().__init__(message)

class PlantError(GardenError):
    pass

class WaterError(GardenError):
    pass

def error_types():
    try:
        print("Testing PlantError...")
        raise PlantError("The tomato plant is wilting!")
    except PlantError as error:
        print(f"Caught {error.__class__.__name__}: {error}")
    print()

    try:
        print("Testing WaterError...")
        raise WaterError("Not enough water in the tank!")
    except WaterError as error:
        print(f"Caught {error.__class__.__name__}: {error}")
    print()

    try:
        print("Testing catching all GardenError...")
        raise GardenError("The tomato plant is wilting!")
    except GardenError as error:
        print(f"Caught {error.__class__.__name__}: {error}")
    try:
        raise GardenError("Not enough water in the tank!")
    except GardenError as error:
        print(f"Caught {error.__class__.__name__}: {error}")
    print()

if __name__ == "__main__":
    print("=== Custom Garden Errors Demo ===")
    print()
    error_types()
    print("All error types tested successfully!")