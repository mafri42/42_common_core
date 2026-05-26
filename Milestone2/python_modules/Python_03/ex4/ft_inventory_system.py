import sys

print("=== Inventory System Analysis ===")

args = sys.argv[1:]
inventory = {}

for param in args:
    if ":" not in param:
        print(f"Error - invalid parameter '{param}'")
        continue
    item, quantity = param.split(":")
    if item in inventory:
        print(f"Redundant item '{item}' - discarding")
        continue
    try:
        quantity = int(quantity)
    except ValueError:
        print(
            f"Quantity error for '{item}': "
            f"invalid literal for int() with base 10: '{quantity}'"
        )
        continue
    inventory[item] = quantity
print("Got inventory:", inventory)
items = list(inventory.keys())
print("Item list:", items)
total = sum(inventory.values())
print("Total quantity of the", len(inventory), "items:", total)
for item in inventory:
    percent = (inventory[item] / total) * 100
    print("Item", item, "represents", round(percent, 1), "%")
max_item = min_item = None
max_qty = -1
min_qty = float("inf")
for item, qty in inventory.items():
    if qty > max_qty:
        max_qty = qty
        max_item = item
    if qty < min_qty:
        min_qty = qty
        min_item = item
print("Item most abundant:", max_item, "with quantity", max_qty)
print("Item least abundant:", min_item, "with quantity", min_qty)
inventory["magic_item"] = 1
print("Updated inventory:", inventory)
