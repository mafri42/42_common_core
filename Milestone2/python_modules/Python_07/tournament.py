from ex2.strategy import (
    BattleStrategy,
    NormalStrategy,
    Aggressivestrategy,
    DefensiveStrategy,
    InvalidCombination,
)
from ex1 import HealingCreatureFactory, TransformCreatureFactory
from ex0 import CreatureFactory, FlameFactory, AquaFactory


def battle(opponent: list[tuple[CreatureFactory, BattleStrategy]]) -> None:
    print("*** Tournament ***")
    print(f"{len(opponent)} opponents involved")
    opp = []
    for facto, strategy in opponent:
        creature = facto.create_base()
        opp.append((creature, strategy))
    for i in range(len(opp)):
        for j in range(i + 1, len(opp)):

            c1, strat1 = opp[i]
            c2, strat2 = opp[j]

            print("\n* Battle *")
            print(c1.describe())
            print(" vs.")
            print(c2.describe())
            print(" now fight!")

            try:
                result = strat1.act(c1)
                if isinstance(result, tuple):
                    for line in result:
                        print(line)
                else:
                    print(result)
                result2 = strat2.act(c2)
                if isinstance(result2, tuple):
                    for linea in result2:
                        print(linea)
                else:
                    print(result2)
            except InvalidCombination as e:
                print(f"Battle error, aborting tournament: {e}")
                return


if __name__ == "__main__":
    print("Tournament 0 (basic)")
    print(" [ (Flameling+Normal), (Healing+Defensive) ]")

    opponents1 = [
        (FlameFactory(), NormalStrategy()),
        (HealingCreatureFactory(), DefensiveStrategy())
    ]
    battle(opponents1)
    print("\nTorunament 1 (error)")
    print(" [ (Flameling+Aggressive), (Healing+Defensive) ]")
    opponents2 = [
        (FlameFactory(), Aggressivestrategy()),
        (HealingCreatureFactory(), DefensiveStrategy())
    ]
    battle(opponents2)
    print("\nTournament 2 (multiple)")
    print(" [ (Aquabub+Normal), (Healing+Defensive), (Transform+Aggressive) ]")
    opponents3 = [
        (AquaFactory(), NormalStrategy()),
        (HealingCreatureFactory(), DefensiveStrategy()),
        (TransformCreatureFactory(), Aggressivestrategy())
    ]
