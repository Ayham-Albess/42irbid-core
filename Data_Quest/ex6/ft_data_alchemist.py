import random

if __name__ == "__main__":
    print("=== Game Data Alchemist ===\n")
    players = ["Alice", "bob", "Charlie", "dylan",
               "Emma", "Gregory", "john", "kevin", "Liam"]
    ch = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    l1 = [i.capitalize() for i in players]
    l2 = [i for i in players if i[0] in ch]
    print(f"Initial list of players:  {players}")
    print(f"New list with all names capitalized:  {l1}")
    print(f"New list of capitalized names only:  {l2}\n")
    dic = {name: random.randrange(1, 1000) for name in l1}
    print(f"Score dict:  {dic}")
    avg = 0
    for key in dic:
        avg += dic[key]
    avg = avg / len(dic)
    print(f"Score average is {avg:.2f}")
    high = {key: dic[key] for key in dic if dic[key] > avg}

    print(f"High scores:  {high}")
