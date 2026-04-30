class Plant:
    def __init__(self, name: str, height: float, age: int) -> None:
        self._name = name 
        self._height = height
        self._age = age

class Flower(Plant):
        def __init__(self, name: str, height: float, age: int, color: str) -> None:
            super().__init__(name, height, age)
            self._color = color
            self._bloomed = False

        def bloom(self):
            if self._bloomed:
                print(f"{self._name} hasn't bloomed yet [asking the {self._name} to bloom]")
            else:  
                self._bloomed = True
                print(f"{self._name} is blooming beautifully!") 
        
        def show(self):
             