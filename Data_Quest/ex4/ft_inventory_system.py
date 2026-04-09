import sys

if __name__ == "__main__":
    print("=== Inventory System Analysis ===")
    inventory: dict[str, int] = {}

    for arg in sys.argv[1:]:
        if arg.count(':') != 1:
            print(f"Error - invalid parameter '{arg}'")
            continue

        item = arg.split(':')

        if item[0] in inventory:
            print(f"Redundant item '{item[0]}' - discarding")
            continue

        try:
            key = item[0]
            value = int(item[1])
        except ValueError:
            print(f"Quantity error for '{item[0]}':"
                  f"  invalid literal for int() with base 10:\n'{item[1]}'")
            continue

        inventory[key] = value

    print(f"Got inventory: {inventory}")

    items = list(inventory.keys())
    print(f"Item list: {items}")

    total = sum(inventory.values())
    print(f"Total quantity of the {len(items)} items: {total}")

    for key in items:
        percent = round((inventory[key] / total) * 100, 1)
        print(f"Item {key} represents {percent}%")

    max_item = items[0]
    min_item = items[0]

    for key in items[1:]:
        if inventory[key] > inventory[max_item]:
            max_item = key
        if inventory[key] < inventory[min_item]:
            min_item = key

    print(f"Item most abundant: {max_item}"
          f" with quantity {inventory[max_item]}")
    print(f"Item least abundant: {min_item} "
          f"with quantity {inventory[min_item]}")

    inventory.update({'magic_item': 1})
    print(f"Updated inventory: {inventory}")
