from typing import Callable

def fireball(target: str, power: int) -> str:
    return f"Fireball hits {target}"

def heal(target: str, power: int) -> str:
    return f"Heals {target}"

def shot(target: str, power: int) -> str:
    return f"Shot {target}"

def raw_power_spell(target: str, power: int) -> str:
    return str(power)

def condition(target: str, power: int) -> bool:
    if target and power >= 10:
        return True
    return False


def spell_combiner(spell1: Callable, spell2: Callable) -> Callable:
    def combined_spell(target: str, power: int) -> tuple[str, str]:
        return (spell1(target, power), spell2(target, power))
    return combined_spell


def power_amplifier(base_spell: Callable, multiplier: int) -> Callable:
    def amplified_spell(target: str, power: int) -> str:
        return base_spell(target, power * multiplier)
    return amplified_spell


def conditional_caster(condition: Callable, spell: Callable) -> Callable:
    def conditionally_cast(target: str, power: int) -> str:
        if condition(target, power):
            return spell(target, power)
        return "Spell fizzled"
    return conditionally_cast


def spell_sequence(spells: list[Callable]) -> Callable:
    def cast_sequence(target: str, power: int) -> list[str]:
        return [spell(target, power) for spell in spells]
    return cast_sequence



if __name__ == "__main__":
    # === Exercise 1 Test Data ===
    test_values = [15, 12, 5]
    test_targets = ['Dragon', 'Goblin', 'Wizard', 'Knight']

    print("\nTesting spell combiner...")
    combiner = spell_combiner(fireball, heal)
    for target, power in zip(test_targets, test_values):
        result = combiner(target, power)
        print(f"Casting on {target} (Power {power}) -> {', '.join(result)}")

    print("\nTesting power amplifier...")
    amplifier = power_amplifier(raw_power_spell, 3)
    for target, power in zip(test_targets, test_values):
        original = raw_power_spell(target, power)
        amplified = amplifier(target, power)
        print(f"Target: {target} -> Original power: {original}, Amplified: {amplified}")

    print("\nTesting conditional caster...")
    conditioner = conditional_caster(condition, fireball)
    for target, power in zip(test_targets, test_values):
        result = conditioner(target, power)
        print(f"Target: {target} (Power {power}) -> {result}")
    
    print("\nTesting spell sequence...")
    sequence = spell_sequence([fireball, heal, shot])
    for target, power in zip(test_targets, test_values):
        result = sequence(target, power)
        print(result)


