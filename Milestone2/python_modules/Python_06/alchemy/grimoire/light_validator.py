def validate_ingredients(ingredients: str) -> str:
    from .light_spellbook import light_spell_allowed_ingredients
    allowed = light_spell_allowed_ingredients()

    used = [i.strip().lower() for i in ingredients.split(",")]

    if any(i in allowed for i in used):
        return f"{ingredients} - VALID"
    else:
        return f"{ingredients} - INVALID"
