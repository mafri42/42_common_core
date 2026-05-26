import random

print("=== Achievement Tracker System ===")

achievements = [
    "Crafting Genius",
    "World Savior",
    "Master Explorer",
    "Collector Supreme",
    "Untouchable",
    "Boss Slayer",
    "Strategist",
    "Unstoppable",
    "Speed Runner",
    "Survivor",
    "Treasure Hunter",
    "First Steps",
    "Sharp Mind",
    "Hidden Path Finder"
]


def gen_player_achievements():
    number = random.randint(5, 9)
    player_set = set()
    for _ in range(number):
        achievement = random.choice(achievements)
        player_set.add(achievement)
    return player_set


alice = gen_player_achievements()
bob = gen_player_achievements()
charlie = gen_player_achievements()
dylan = gen_player_achievements()
print("\nPlayer Alice:", alice)
print("Player Bob:", bob)
print("Player Charlie:", charlie)
print("Player Dylan:", dylan)

all_achievements = alice.union(bob, charlie, dylan)
print("\nAll distinct achievements:", all_achievements)

common = alice.intersection(bob, charlie, dylan)
print("\nCommon achievements:", common)

only_alice = alice.difference(bob.union(charlie, dylan))
print("\nOnly Alice has:", only_alice)

only_bob = bob.difference(alice.union(charlie, dylan))
print("Only Bob has:", only_bob)

only_charlie = charlie.difference(alice.union(bob, dylan))
print("Only Charlie has:", only_charlie)

only_dylan = dylan.difference(alice.union(bob, charlie))
print("Only Dylan has:", only_dylan)

missing_alice = all_achievements.difference(alice)
print("\nAlice is missing:", missing_alice)

missing_bob = all_achievements.difference(bob)
print("Bob is missing:", missing_bob)

missing_charlie = all_achievements.difference(charlie)
print("Charlie is missing:", missing_charlie)

missing_dylan = all_achievements.difference(dylan)
print("Dylan is missing:", missing_dylan)
