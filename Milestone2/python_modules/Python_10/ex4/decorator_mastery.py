import functools
import time
from collections.abc import Callable

def spell_timer(func: Callable) -> Callable:
    @functools.wraps(func)
    def wrapper(*arg: any, **kwargs: any) -> Callable:
        print(f"Casting {func.__name__}...")
        start = time.time()
        value = func(*arg, **kwargs)
        end = time.time()
        print(f"Spell completed in {float(end - start):.3f} seconds")
        return value 
    return wrapper

def power_validator(min_power: int) -> Callable:
    def validate(func: Callable) -> Callable:
        def print_message() -> str:
            return "Insufficient power for this spell"

        @functools.wraps(func)
        def wrapper(*arg: any, **kwargs: any) -> any:
            if arg[0] >= min_power:
                return func(*arg, **kwargs)
            else:
                return print_message()
        return wrapper
    return validate

def retry_spell(max_attempts: int) -> Callable:
    def retry(func: Callable) -> Callable:
        @functools.wraps(func)
        def wrapper(*arg: any, **kwargs: any) -> any:
            i = 0
            while i < max_attempts:
                try:
                    return func(*arg, **kwargs)
                except ValueError:
                    print(f'Spell failed, retrying... (attempt {i + 1}/'
                          f'{max_attempts})')
                    i += 1
            return f"Spell casting failed after {max_attempts} attempts"
        return wrapper
    return retry

class MageGuild:
    @staticmethod
    def validate_mage_name(name: str) -> bool:
        if len(name) < 3:
            return False
        for letter in name:
            if (((letter < 'a' or letter > 'z') and (letter < 'A' or letter > 'Z')) and letter != ' '):
                return False
        return True

    def cast_spell(self, spell_name: str, power: int) -> str:
        @power_validator(min_power=10)
        def validate_power(power) -> str:
            return f"Successfully cast {spell_name} with {power} power"
        return validate_power(power)

@spell_timer
def fireball():
    return "Result: Fireball cast!"

@retry_spell(max_attempts=3)
def retry_spell(num : int):
    if num == 2:
        raise ValueError()
    return "Waaaaaaagh spelled !"

def main() -> None:
    # Master's Tower Test Data
    test_powers = [15, 13, 5, 23]
    spell_names = ['meteor', 'heal', 'freeze', 'darkness']
    mage_names = ['Nova', 'Kai', 'Alex', 'Phoenix', 'Rowan', 'Riley']
    invalid_names = ['Jo', 'A', 'Alex123', 'Test@Name']
    print("Testing spell timer...")
    print(fireball())

    print("\nTesting retrying spell...")
    print(f"{retry_spell(2)}")
    print(retry_spell(1))

    print("\nTesting MageGuild...")
    mage = MageGuild()
    for names, power in zip (spell_names, test_powers):
        print(mage.cast_spell(names, power))
    print("\nValid name:")
    for valid in mage_names:
        print(mage.validate_mage_name(valid))
    print("\nInvalid name:")
    for invalid in invalid_names:
        print(mage.validate_mage_name(invalid))


if __name__ == "__main__":
    main()