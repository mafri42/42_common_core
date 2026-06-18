from .dark_spellbook import dark_spell_allowed_ingredients


def validate_ingredients(ingredients: str) -> str:
    allowed = dark_spell_allowed_ingredients()

    used = [i.strip().lower() for i in ingredients.split(",")]

    if any(i in allowed for i in used):
        return f"{ingredients} - VALID"
    else:
        return f"{ingredients} - INVALID"
