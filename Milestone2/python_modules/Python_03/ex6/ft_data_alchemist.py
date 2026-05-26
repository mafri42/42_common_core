import random

print("=== Game Data Alchemist ===")

players = ['Alice', 'bob', 'Charlie', 'dylan',
           'Emma', 'Gregory', 'john', 'kevin', 'Liam']

print("Initial list of players:", players)

capitalized = [name.capitalize() for name in players]
print("New list with all names capitalized:", capitalized)

only_capitalized = [name for name in players if name[0].isupper()]
print("New list of capitalized names only:", only_capitalized)

scores = {name: random.randint(0, 1000) for name in capitalized}
print("Score dict:", scores)

average = sum(scores.values()) / len(scores)
print("Score average is", round(average, 2))

high_scores = {name: score for name, score in scores.items()
               if score > average}
print("High scores:", high_scores)
