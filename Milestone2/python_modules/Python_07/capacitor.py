from ex1.factory import HealingCreatureFactory, TransformCreatureFactory


def test_heal(healing: HealingCreatureFactory) -> None:
    print("Testing Creature with healing capability")
    Sproutling = healing.create_base()
    Bloomelle = healing.create_evolved()
    print(" base:")
    print(Sproutling.describe())
    print(Sproutling.attack())
    print(Sproutling.heal())
    print(" evolved:")
    print(Bloomelle.describe())
    print(Bloomelle.attack())
    print(Bloomelle.heal())


def test_transform(transform: TransformCreatureFactory) -> None:
    print("Testing Creature with transform capability")
    Shiftling = transform.create_base()
    Morphagon = transform.create_evolved()
    print(" base:")
    print(Shiftling.describe())
    print(Shiftling.attack())
    print(Shiftling.transform())
    print(Shiftling.attack())
    print(Shiftling.revert())
    print(" evolved:")
    print(Morphagon.describe())
    print(Morphagon.attack())
    print(Morphagon.transform())
    print(Morphagon.attack())
    print(Morphagon.revert())


if __name__ == "__main__":
    test_heal(HealingCreatureFactory())
    print()
    print()
    test_transform(TransformCreatureFactory())
    print()
