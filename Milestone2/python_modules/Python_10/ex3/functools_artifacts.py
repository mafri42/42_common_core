import functools
import operator
from typing import Callable, Any

def spell_reducer(spells: list[int], operation: str) -> int:
    if operation == 'add':
        return functools.reduce(
            lambda accumulator, item: operator.add(accumulator, item), spells
        )
    elif operation == 'multiply':
        return functools.reduce(
            lambda accumulator, item: operator.mul(accumulator, item), spells
        )
    elif operation == 'max':
         return functools.reduce(
            lambda accumulator, item: item if item > accumulator
            else accumulator, spells
        )
    elif operation == 'min':
        return functools.reduce(
            lambda accumulator, item: item if item < accumulator
            else accumulator, spells
        )
    raise ValueError(f'Invalid operation : ({operation})')

def partial_enchanter(base_enchantment: Callable) -> dict[str, Callable]:
    return {
        'fire_enchant': functools.partial(
            base_enchantment, power=50, element='fire'),

        'ice_enchant': functools.partial(
            base_enchantment, power=60, element='ice'),

        'lightning_enchant': functools.partial(
            base_enchantment, power=70, element='lightning'),
    }

@functools.lru_cache 
def memoizied_fibonacci(n: int) -> int:
    if n == 0:
        return 0
    if n == 1:
        return 1
    return memoizied_fibonacci(n - 1) + memoizied_fibonacci(n - 2)

def spell_dispatcher() -> Callable[[Any], str]:
    
    # 1. Definiamo la funzione base con il decoratore.
    # Questo è il comportamento di default o di fallback (per tipi sconosciuti).
    @functools.singledispatch
    def cast_spell(spell: Any) -> str:
        return "Unknown spell type"

    @cast_spell.register
    def _(spell: int) -> str:
        return f"Damage spell: {spell} damage"

    @cast_spell.register
    def _(spell: str) -> str:
        return f"Enchantment: {spell}"

    @cast_spell.register
    def _(spell: list) -> str:
        return f"Multi-cast: {len(spell)} spells"

    return cast_spell

def main() -> None:
    try:
        # Ancient Library Test Data
        spell_powers = [36, 13, 45, 12, 19, 47]
        operations = ['add', 'multiply', 'max', 'min']
        fibonacci_tests = [11, 10, 13]
        
        print('\nTesting Spell Reducer...')
        print(f"{operations[0]}:", spell_reducer(spell_powers, operations[0]))
        print(f"{operations[1]}:", spell_reducer(spell_powers, operations[1]))
        print(f"{operations[2]}:", spell_reducer(spell_powers, operations[2]))
        print(f"{operations[3]}:", spell_reducer(spell_powers, operations[3]))

        print('\nTesting Base Enchantment...')
        def base_enchantment(power, element, target) -> str:
            return f"Attack {target} with {element} (power of {power})"
        enchants = partial_enchanter(base_enchantment)
        print(enchants['fire_enchant'](target='killer bunny'))
        print(enchants['ice_enchant'](target='Laurent'))

        print('\nTesting memoized fibonacci...')
        for fib in fibonacci_tests:
            print(f"Fib({fib}) : {memoizied_fibonacci(fib)}")

        print('\nTesting spell dispatcher...')
        dispatcher = spell_dispatcher()
        print(dispatcher(42))
        print(dispatcher("fireball"))
        print(dispatcher(["haste", "heal", "shield"]))
        print(dispatcher({"item" : "sword", "spell": "dark_magic"}))
    except ValueError as e:
        print(f"Error: {e}")

if __name__ == "__main__":
    main()