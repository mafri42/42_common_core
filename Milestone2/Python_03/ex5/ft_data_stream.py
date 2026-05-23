import random

print("=== Game Data Stream Processor ===")

def gen_event():
    players = ["alice", "bob", "charlie", "dylan"]
    actions = [
        "move",
        "grab",
        "use",
        "swim",
        "run",
        "climb",
        "release"
    ]

    while True:
        player = random.choice(players)
        action = random.choice(actions)
        
        event = (player, action)
        yield event

gen = gen_event()
for i in range(1000):
        event = next(gen)
        print(f"Event {i}: Player {event[0]} did action {event[1]}")

event_list = []
for i in range(10):
    event_list.append(next(gen))
print("Built list of 10 events:", event_list)

def consume_event(event_list):
    while event_list:
        event = random.choice(event_list)
        event_list.remove(event)
        yield event

for event in consume_event(event_list):
    print("Got event from list:", event)
    print("Remains in list:", event_list)