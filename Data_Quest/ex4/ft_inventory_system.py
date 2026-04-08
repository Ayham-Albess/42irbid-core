import sys

if __name__ == "__main__":
    print("=== Inventory System Analysis ===")
    inventory = {}
    for arg in sys.argv[1:]:
        if arg.count(':') != 1:
            print(f"Error - invalid parameter '{arg}'")
            continue
        item = arg.split(':')
        if item[0] in inventory:
            print(f"Redundant item '{item}' - discarding")
            continue
        try:
            item[1] = int(item[1])
        except ValueError:
            print(f"Quantity error for '{item[0]}':"
                  f"  invalid literal for int() with base 10:\n'{item[1]}'")
            continue
        inventory[item[0]] = item[1]
    print(f"Got inventory: {inventory}")
    items = list(inventory.keys())
    print(f"Item list: {items}")
    total = sum(inventory.values())
    print(f"Total quantity of the {len(items)} items: {total}")
    for item in items:
        percent = round((inventory[item] / total) * 100, 1)
        print(f"Item {item} represents {percent}%")
    max_item = None
    min_item = None
    for item in items:
        if max_item is None or inventory[item] > inventory[max_item]:
            max_item = item
        if min_item is None or inventory[item] < inventory[min_item]:
            min_item = item
    print(f"Item most abundant: {max_item}"
          f" with quantity {inventory[max_item]}")
    print(f"Item least abundant: {min_item} "
          f"with quantity {inventory[min_item]}")
    inventory.update({'magic_item': 1})
    print(f"Updated inventory: {inventory}")
