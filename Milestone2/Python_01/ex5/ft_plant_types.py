#!/usr/bin/python3
class Plant:
    def __init__(
        self,
        name: str,
        height: float,
        days: int,
        growth: float
    ) -> None:
        self.name = name
        self.height = height
        self.days = days
        self.growth = growth

    def show(self) -> None:
        print(f"{self.name}: {self.height}cm, {self.days} days old")

    def grow(self) -> None:
        self.height += self.growth

    def age(self, i: int) -> None:
        self.days += i


class Flower(Plant):
    def __init__(
        self,
        name: str,
        height: float,
        days: int,
        color: str,
        growth: float,
    ) -> None:
        super().__init__(name, height, days, growth)
        self.color = color

    def show(self) -> None:
        super().show()
        print(f" Color: {self.color}")

    def bloom(self) -> None:
        self.show()
        print(f" {self.name} has not bloomed yet")
        print(f"[asking the {self.name.lower()} to bloom]")
        self.show()
        print(f"{self.name} is blooming beautifully!")


class Tree(Plant):
    def __init__(
        self,
        name: str,
        height: float,
        days: int,
        growth: float,
        trunk_diameter: float,
    ) -> None:
        super().__init__(name, height, days, growth)
        self.trunk_diameter = trunk_diameter

    def show(self) -> None:
        super().show()
        print(f" Trunk diameter: {self.trunk_diameter}cm")

    def produce_shade(self) -> None:
        print(f"[asking the {self.name.lower()} to produce shade]")
        print(
            f"Tree {self.name} now produces a shade of "
            f"{self.height}cm long and "
            f"{self.trunk_diameter}cm wide."
        )


class Vegetable(Plant):
    def __init__(
        self,
        name: str,
        height: float,
        days: int,
        harvest_season: str,
        growth: float,
    ) -> None:
        super().__init__(name, height, days, growth)
        self.harvest_season = harvest_season
        self.nutritional_value = 0

    def show(self) -> None:
        super().show()
        print(f" Harvest season: {self.harvest_season}")
        print(f" Nutritional value: {self.nutritional_value}")

    def grow_veg(self, i: int) -> None:
        print(f"[make {self.name.lower()} grow and age for {i} days]")
        self.age(i)
        self.grow()
        self.nutritional_value += i


if __name__ == "__main__":
    print("=== Garden Plant Types ===")
    print("=== Flower")
    flower = Flower("Rose", 15.0, 10, "red", 0)
    flower.bloom()
    print()
    print("=== Tree")
    tree = Tree("Oak", 200.0, 365, 1, 5.0)
    tree.show()
    tree.produce_shade()
    print()
    print("=== Vegetable")
    vegetable = Vegetable("Tomato", 12, 10, "April", 0)
    i = 0
    vegetable.show()
    i = 20
    vegetable.grow_veg(i)
    vegetable.show()
