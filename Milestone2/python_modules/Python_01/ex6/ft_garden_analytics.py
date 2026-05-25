#!/usr/bin/python3
class Plant:
    grow_count: int = 0
    age_count: int = 0
    show_count: int = 0

    def __init__(self, name: str, h: float, days: int, gw: float) -> None:
        self.name = name
        self.h = h
        self.days = days
        self.gw = gw

    def show(self) -> None:
        print(f"{self.name}: {float(self.h)}cm, {self.days} days old")
        self.show_count += 1

    @staticmethod
    def age_check(age: int) -> None:
        if age > 365:
            print(f"Is {age} days more than a year? -> True")
        else:
            print(f"Is {age} days more than a year? -> False")

    @classmethod
    def create_plant(cls) -> "Plant":
        return cls("Uknown plant", 0, 0, 0)

    def grow(self) -> None:
        self.h = self.h + self.gw
        self.grow_count += 1

    def age(self, i: int) -> None:
        self.days += i
        self.age_count += 1


class Flower(Plant):
    def __init__(
        self, name: str, h: float,
        days: int, gw: float, color: str
    ) -> None:
        super().__init__(name, h, days, gw)
        self.color = color

    def show(self) -> None:
        super().show()
        print(f" Color: {self.color}")

    def bloom(self) -> None:
        self.show()
        print(f" {self.name} has not bloomed yet")
        display_statistic(self)
        print(f"[asking the {self.name.lower()} to grow and bloom]")
        self.grow()
        self.show()
        print(f" {self.name} is blooming beautifully!")
        display_statistic(self)


class Seed(Flower):
    def __init__(
        self, name: str, h: float,
        days: int, gw: float, color: str
    ) -> None:
        super().__init__(name, h, days, gw, color)
        self.amount = 0

    def age_and_bloom(self) -> None:
        self.show()
        print(f" {self.name} has not bloomed yet")
        print(f" Seeds: {self.amount}")
        print(f"[asking the {self.name.lower()} to grow and bloom]")
        self.grow()
        self.age(20)
        self.amount += 1
        self.show()
        print(f" {self.name} is blooming beautifully!")
        print(f" Seeds: {self.amount}")


class Tree(Plant):
    def __init__(self, name: str, h: float, days: int,
                 gw: float, trunk_diameter: float) -> None:
        super().__init__(name, h, days, gw)
        self.trunk_diameter = trunk_diameter
        self.shades = 0

    def show(self) -> None:
        super().show()
        print(f" Trunk diameter: {float(self.trunk_diameter)}cm")

    def produce_shade(self) -> None:
        self.show()
        display_statistic(self)
        print(f" {self.shades} shade")
        print(f"[asking the {self.name.lower()} to produce shade]")
        print(f"Tree {self.name} now produces a shade of {self.h}"
              f"cm long and {float(self.trunk_diameter)}cm wide.")
        self.shades += 1
        display_statistic(self)
        print(f" {self.shades} shade")


def display_statistic(plant: Plant) -> None:
    print(f"[statistics for {plant.name}]")
    print(f"Stats: {plant.grow_count} grow, "
          f"{plant.age_count} age, {plant.show_count} show")


if __name__ == "__main__":
    print("=== Garden statistic ===")
    print("=== Check year-old ===")
    Plant.age_check(30)
    Plant.age_check(400)
    print()
    print("=== Flower")
    flower = Flower("Rose", 15, 10, 8, "red")
    flower.bloom()
    print()
    print("=== Tree")
    tree = Tree("Bonsai", 200, 365, 8, 5)
    tree.produce_shade()
    print()
    print("=== Seed")
    sunflower = Seed("Sunflower", 80, 45, 30, "yellow")
    sunflower.age_and_bloom()
    print()
    print("=== Anonymus")
    anon = Plant.create_plant()
    anon.show()
    display_statistic(anon)
