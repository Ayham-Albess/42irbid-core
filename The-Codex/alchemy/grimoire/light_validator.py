def validate_ingredients(ingredients: str) -> str:
    from .light_spellbook import light_spell_allowed_ingredients

    allowed = light_spell_allowed_ingredients()
    ingredients_lower = ingredients.lower()

    valid = any(item in ingredients_lower for item in allowed)

    status = "VALID" if valid else "INVALID"
    return f"{ingredients} - {status}"
