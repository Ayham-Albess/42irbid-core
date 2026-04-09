from typing import Generator
import random


def gen_event() -> Generator[tuple, None, None]:
    names = ["bob", "alice", "alice", "charlie"]
    actions = ["use", "move", "grab", "swim", "climb", "release"]
    for i in range(0, 1000):
        yield (random.choice(names), random.choice(actions))
    for i in range(0, 10):
        yield (random.choice(names), random.choice(actions))


def consume_event(ret_list) -> Generator[tuple, None, None]:
    for i in range(0, 10):
        x = random.choice(ret_list)
        ret_list.remove(x)
        yield x


if __name__ == "__main__":
    print("=== Game Data Stream Processor ===")
    g = gen_event()
    ret_list = []
    for i in range(0, 1000):
        x = next(g)
        print(f"Event {i}:  Player {x[0]} did action {x[1]}")
    for i in range(0, 10):
        ret_list += [next(g)]
    print(f"Built list of 10 events:  {ret_list}")
    g = consume_event(ret_list)
    for i in range(0, 10):
        x = next(g)
        print(f"Got event from list:  {x}")
        print(f"Remains in list:  {ret_list}")
