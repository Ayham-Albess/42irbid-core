import alchemy

print("=== Alembic 4 ===")
print("Testing create_air:", alchemy.create_air())

print("Testing hidden create_earth:")
print(alchemy.create_earth())   # type: ignore[attr-defined]
