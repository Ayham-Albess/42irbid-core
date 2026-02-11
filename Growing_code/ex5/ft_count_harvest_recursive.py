def helper(i: int, days: int):
    if i == days:
        print("Harvest time!")
        return
    print("Day", i + 1)
    helper(i + 1, days)


def ft_count_harvest_recursive():
    days: int = int(input("Days until harvest: "))
    helper(0, days)
