def ft_plant_age():
    plant_age = int(input("Enter plant age: "))
    if plant_age > 60:
        print("Plant is ready to harvest!")
    elif plant_age <= 60:
        print("Plant needs more time to grow.")
