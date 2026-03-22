def garden_operations():
    try:
        s = "Caught ValueError: invalid literal for int()\n"
        print("Testing ValueError...")
        x = "abc"
        for i in x:
            if (i < '0' or i > '9'):
                raise ValueError(s)
    except ValueError as e:
        print(e)
    try:
        print("Testing ZeroDivisionError...")
        x = 15/0
        x = x*x
    except ZeroDivisionError:
        print("Caught ZeroDivisionError: division by zero\n")
    try:
        print("Testing FileNotFoundError...")
        f = open("texrt.txt")
        f = f - "a"
        f.close()
    except FileNotFoundError:
        print("Caught FileNotFoundError: No such file ’texrt.txt’\n")
    try:
        print("Testing KeyError...")
        direc = {'elbess': 'ayham'}
        s = direc['rosan']
    except KeyError:
        print("Caught KeyError: ’elbess’\n")
    try:
        print("Testing multiple errors together...")
        x = "abc"/0
        x = x*x
    except (TypeError, ZeroDivisionError):
        print("Caught an error, but program continues!\n")
    print("All error types tested successfully!")


if __name__ == "__main__":
    print("=== Garden Error Types Demo ===\n")
    garden_operations()
