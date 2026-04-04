class Plant:
    def __init__(self, name: str, height: float, age: int) -> None:
        self.name = name 
        self.height = height
        self.days = age

    def grow(self):
        self.height += 0.8

    def age(self):
        self.days += 1

def ft_plant_growth():
    print("=== Garden Plant Growth ===")

    rose = Plant("Rose", 25.0, 30)
    rose_growth = rose.height
    print(f"Rose: {round(rose.height, 1)}cm, {rose.days} days old")

    day = 1
    while day <= 7:

        rose.grow()
        rose.age()

        print(f"=== Day {day} ===")
        print(f"Rose: {round(rose.height, 1)}cm, {rose.days} days old")
    
        day += 1
    print("Growth this week: ", round(rose.height - rose_growth, 1), "cm")

    
if __name__ == "__main__":
    ft_plant_growth()
