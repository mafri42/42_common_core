import sys

print("=== Player Score Analytics ===")

args = sys.argv[1:] #prendi la lista da indice 1 fino alla fine
scores = []

for x in args: #prendere ogni elemento di una lista
    try:
        scores.append(int(x)) #trasformare x in numero, aggiungerlo alla lista scores
    except ValueError:
        print(f"Invalid parameter: '{x}'")

if len(scores) == 0:
    print(
        "No scores provided. Usage: "
        "python3 ft_score_analytics.py <score1> <score2> ..."
    )
else:
    print(f"Scores processed: {scores}")
    print("Total players:", len(scores))
    print("Total score:", sum(scores))
    print("Average score:", sum(scores) / len(scores))
    print("High score:", max(scores))
    print("Low score:", min(scores))
    print("Score range:", max(scores) - min(scores))
