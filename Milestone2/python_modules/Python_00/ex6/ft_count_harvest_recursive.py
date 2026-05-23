def ft_count_harvest_recursive():
    harvest_days = int(input("Days until harvest: "))
    count_days(1, harvest_days)


def count_days(day, harvest_days):
    if day > harvest_days:
        print("Harvest time!")
        return
    print(f"Day {day}")
    count_days(day + 1, harvest_days)
