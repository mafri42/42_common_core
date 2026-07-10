def artifact_sorter(artifacts: list[dict]) -> list[dict]:
    return sorted(artifacts, key=lambda a: a["power"], reverse=True)

def power_filter(mages: list[dict], min_power: int) -> list[dict]:
    return list(filter(lambda m: m["power"] >= min_power, mages))

def spell_transformer(spells: list[str]) -> list[str]:
    return list(map(lambda s: f"* {s} *", spells))


def mage_stats(mages: list[dict]) -> dict:
    return {
        "max_power": max(mages, key=lambda m: m["power"])["power"],
        "min_power": min(mages, key=lambda m: m["power"])["power"],
        "avg_power": round(sum(map(lambda m: m["power"], mages)) / len(mages), 2)
    }


if __name__ == "__main__":
    # Lambda Sanctum Test Data
    artifacts = [{'name': 'Crystal Orb', 'power': 76, 'type': 'armor'}, {'name': 'Storm Crown', 'power': 100, 'type': 'relic'}, {'name': 'Crystal Orb', 'power': 110, 'type': 'focus'}, {'name': 'Crystal Orb', 'power': 74, 'type': 'relic'}]
    mages = [{'name': 'Morgan', 'power': 80, 'element': 'shadow'}, {'name': 'Luna', 'power': 92, 'element': 'light'}, {'name': 'Zara', 'power': 99, 'element': 'lightning'}, {'name': 'Rowan', 'power': 82, 'element': 'wind'}, {'name': 'Ember', 'power': 96, 'element': 'ice'}]
    spells = ['meteor', 'darkness', 'flash', 'shield']

    print("\nTesting artifact sorter...")
    items = []
    for item in artifact_sorter(artifacts):
        items.append(item)
    if len(items) >= 2:
        print(f"{items[0]['name']} ({items[0]['power']}) comes before {items[1]['name']} ({items[1]['power']})")
    else:
        print("Not enough artifacts.")

    print("\nTesting power filter...")
    filter = power_filter(mages, 81)
    for mage in filter:
        print(f"Name {mage['name']} power {mage['power']}")

    print("\nTesting mage stats...")
    power = mage_stats(mages)
    print(power)

    print("\nTesting spell transformer...")
    for item in spell_transformer(spells):
        print(item, end=" ")
    print("")