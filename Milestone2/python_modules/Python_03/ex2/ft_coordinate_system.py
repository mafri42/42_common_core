import math

print("=== Game Coordinate System ===")

print("\nGet a first set of coordinates")
pos1 = None
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
        for part in parts:
            clean = part.strip()
            try:
                float(clean)
            except ValueError:
                print(f"Error on parameter '{clean}': {e}")
                break
        continue
    pos = (x, y, z)
    if pos1 is None:
        print("Got a first tuple: ", pos)
        print(f"It includes: X={pos[0]}, Y={pos[1]}, Z={pos[2]}")
        distance = math.sqrt(x**2 + y**2 + z**2)
        print("Distance to center:", round(distance, 4))
        pos1 = pos
    else:
        distance1 = math.sqrt(
            (pos[0] - pos1[0])**2 +
            (pos[1] - pos1[1])**2 +
            (pos[2] - pos1[2])**2
        )
        print(
            "Distance between the 2 sets of coordinates:",
            round(distance1, 4)
        )
        break
    print("\nGet a second set of coordinates")
