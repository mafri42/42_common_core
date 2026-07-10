from typing import Callable

def mage_counter() -> Callable:
    counter = 0

    def count() -> int:
        nonlocal counter
        counter += 1
        return counter
    return count


def spell_accumulator(initial_power: int) -> Callable:
    accumulator = initial_power

    def accumulate(amount: int) -> int:
        nonlocal accumulator
        accumulator += amount
        return accumulator
    return accumulate


def enchantment_factory(enchantment_type: str) -> Callable:
    entype = enchantment_type
    def enchantment_item(item_name: str) -> str:
        return f"{entype} {item_name}"
    return enchantment_item


def memory_vault() -> dict[str, Callable]:
    dictionnary = {}
    def store(key: str, value: int):
        dictionnary[key] = value
        print(f"store {key} = {value}")
    def recall(key: str):
        if key in dictionnary:
            print(f"Recall {key} : {dictionnary[key]}")
            return dictionnary[key]
        else:
            print(f"Recall {key} : Memory not found")
            return "Memory not found"
    return {
        "store": store,
        "recall": recall
    }

def main():
    # Memory Depths Test Data
    initial_powers = [47, 51, 33]
    power_additions = [14, 11, 8, 6, 19]
    enchantment_types = ['Shocking', 'Dark', 'Frozen']
    items_to_enchant = ['Sword', 'Shield', 'Wand', 'Amulet']

    print("Testing mage counter...")
    counter_a = mage_counter()
    print(f"counter_a call 1: {counter_a()}")
    print(f"counter_a call 2: {counter_a()}")
    counter_b = mage_counter()
    print(f"counter_b call 1: {counter_b()}")

    print("\nTesting spell accumulator...")
    for init_power in initial_powers:
        print(f"\nBase {init_power}")
        accumulator = spell_accumulator(init_power)
        for power_add in power_additions:
            print(f"Base {init_power}, add {power_add}: {accumulator(power_add)}")

    print("\nTesting enchantment factory...")
    for enchant in enchantment_types: 
        print(f"\nenchantment {enchant}")
        enchantment = enchantment_factory(enchant)
        for item in items_to_enchant:
            print(f"{enchantment(item)}")

    print("\nTesting memory vault...")
    dictionary = memory_vault()
    dictionary["store"]('secret', 42)
    dictionary["recall"]('secret')
    dictionary["recall"]('unknown')

if __name__ == "__main__":
    main()