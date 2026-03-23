import sys


def my_int(s) -> int:
    digits = "0123456789"
    num = 0
    sign = 1
    i = 0

    if s[0] == '-':
        sign = -1
        i += 1
    elif s[0] == '+':
        i += 1

    while i < len(s):
        c = s[i]
        if c in digits:
            n = 0
            while digits[n] != c:
                n += 1
            num = num * 10 + n
        else:
            break
        i += 1

    return sign * num


if __name__ == "__main__":
    print("=== Inventory System Analysis ===")
    dic = {}
    for i in range(1, len(sys.argv)):
        indix = 0
        for a in sys.argv[i]:
            if a != ':':
                indix += 1
            else:
                break
        dic[sys.argv[i][:indix]] = my_int(sys.argv[i][indix + 1:])
    total = 0
    for val in dic.values():
        total += val
    print(f"Total items in inventory:  {total}")
    print(f"Unique item types:  {len(sys.argv) - 1}\n")
    print("=== Current Inventory ===")
    for key in dic.keys():
        print(f"{key}:  {dic[key]} units ({(dic[key]/total)*100:.1f}%)")
    print("\n=== Inventory Statistics ===")
    lowest = 10
    highest = 0
    name1 = "s"
    name2 = "s"
    for key in dic.keys():
        if dic[key] > highest:
            highest = dic[key]
            name1 = key
        if dic[key] < lowest:
            lowest = dic[key]
            name2 = key
    print(f"Most abundant:  {name1} ({highest} units)")
    print(f"Least abundant:  {name2} ({lowest} unit)\n")
    print("=== Item Categories ===")
    moderate = {}
    scarce = {}
    for k, v in dic.items():
        if v >= 5:
            moderate[k] = v
        else:
            scarce[k] = v
    print(f"Moderate:  {moderate}")
    print(f"Scarce:  {scarce}")
    print("\n=== Management Suggestions ===")
    temp = {}
    for key in dic.keys():
        if dic[key] == lowest:
            temp[key] = dic[key]
    l = list(temp.keys())
    k = list(dic.keys())
    v = list(dic.values())
    print(f"• Restock needed:  {l}")
    print("\n=== Dictionary Properties Demo ===")
    print(f"Dictionary keys:  {k}")
    print(f"Dictionary values:  {v}")
    t = False
    if "sword" in dic:
        t = True
    print(f"Sample lookup - ’sword’ in inventory:  {t}")
