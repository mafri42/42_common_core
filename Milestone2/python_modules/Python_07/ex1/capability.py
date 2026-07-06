from abc import ABC, abstractmethod
from ex0.creature import Creature


class HealCapability(ABC):
    @abstractmethod
    def heal(self) -> str:
        pass


class TransformCapability(ABC):
    @abstractmethod
    def transform(self) -> str:
        pass

    @abstractmethod
    def revert(self) -> str:
        pass


class Sproutling(Creature, HealCapability):
    def heal(self) -> str:
        return f"{self.name} heals itself for a small amount"

    def attack(self) -> str:
        return f"{self.name} uses Vine Whip!"


class Bloomelle(Creature, HealCapability):
    def heal(self) -> str:
        return f"{self.name} heals itself and others for a large amount"

    def attack(self) -> str:
        return f"{self.name} uses Petal Dance!"


class Shiftling(Creature, TransformCapability):
    def __init__(self, name: str, type: str):
        super().__init__(name, type)
        self.evolving = False

    def transform(self) -> str:
        self.evolving = True
        return f"{self.name} shifts into a sharper form!"

    def revert(self) -> str:
        self.evolving = False
        return f"{self.name} returns to normal."

    def attack(self) -> str:
        if not self.evolving:
            return f"{self.name} attacks normally."
        else:
            return f"{self.name} performs a boosted strike!"


class Morphagon(Creature, TransformCapability):
    def __init__(self, name: str, type: str):
        super().__init__(name, type)
        self.evolving = False

    def transform(self) -> str:
        self.evolving = True
        return f"{self.name} morphs into a dragonic battle form!"

    def revert(self) -> str:
        self.evolving = False
        return f"{self.name} stabilizes its form."

    def attack(self) -> str:
        if not self.evolving:
            return f"{self.name} attacks normally."
        else:
            return f"{self.name} unleashes a devastating morph strike!"
