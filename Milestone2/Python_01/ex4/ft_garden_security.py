class Plant:
    def __init__(self, name: str, height: float, age: int) -> None:
        self._name = name
        self._height = 0
        self._age = 0

        self.set_height(height)
        self.set_age(age)

    def show(self) -> None:
        print(f"{self._name}: {self._height}cm, {self._age} days old")

    def grow(self):
        self._height += 0.8

    def age(self):
        self._age += 1

    def set_height(self, new):
        if new < 0:
            print(f"{self._name}: Error, height can't be negative")
            print("Height update rejected")
        else:
            self._height = new

    def set_age(self, new):
        if new < 0:
            print(f"{self._name}: Error, age can't be negative")
            print("Age update rejected")
        else:
            self._age = new

    def get_height(self):
        return self._height

    def get_age(self):
        return self._age


if __name__ == "__main__":
    print("=== Garden Security System ===")

    plant1 = Plant("Rose", 15.0, 10)
    print("Plant created:", end=" ")
    plant1.show()

    plant1.set_height(25)
    plant1.get_height()
    plant1.set_age(30)
    plant1.get_age()
    print(" ")
    plant1.set_height(-5)
    plant1.get_height()
    plant1.set_age(-9)
    plant1.get_age()
    print(" ")

    print("Current state:", end=" ")
    plant1.show()
