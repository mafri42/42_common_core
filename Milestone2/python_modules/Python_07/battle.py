from ex0.factory import CreatureFactory, FlameFactory, AquaFactory


def testing(factory: CreatureFactory) -> None:
    print("Testing factory")
    base = factory.create_base()
    evolved = factory.create_evolved()
    print(base.describe())
    print(base.attack())
    print(evolved.describe())
    print(evolved.attack())


def fight(flame_factory: FlameFactory, aqua_factory: AquaFactory) -> None:
    print("Testing battle")
    flame = flame_factory.create_base()
    aqua = aqua_factory.create_base()
    print(flame.describe())
    print(" vs.")
    print(aqua.describe())
    print(" fight!")
    print(flame.attack())
    print(aqua.attack())


if __name__ == "__main__":
    testing(FlameFactory())
    print()
    testing(AquaFactory())
    print()
    fight(FlameFactory(), AquaFactory())
