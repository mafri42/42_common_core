def validate_ingredients(ingredients: str) -> str:
    allowed = ["earth", "air", "fire", "water"]

    used = [i.strip().lower() for i in ingredients.split(",")]

    if any(i in allowed for i in used):
        return f"{ingredients} - VALID"
    else:
        return f"{ingredients} - INVALID"
