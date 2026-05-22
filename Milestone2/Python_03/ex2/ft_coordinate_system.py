import math

print("=== Game Coordinate System ===")

print("\nGet a first set of coordinates")
while True:
    user_input = input("Enter new coordinates as floats in format 'x,y,z': ")

    parts = user_input.split(",")
    if len(parts) != 3:
        print("Invalid syntax")
        continue
    try:
        x = float(parts[0])
        y = float(parts[1])
        z = float(parts[2])
    except ValueError as e:
        print(f"Error on parameter {e} : could not convert string to float: '{e}'")
        continue
    pos = (x, y, z)
    print("Got a first tuple: ", pos)
    #aggiungi il pezzo
    print("\nGet a second set of coordinates")
