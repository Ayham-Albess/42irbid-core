import math


def dis(x1: float, y1: float, z1: float,
        x2: float, y2: float, z2: float) -> float:
    return (math.sqrt((x2 - x1)**2 + (y2 - y1)**2 + (z2 - z1)**2))


if __name__ == "__main__":
    print("=== Game Coordinate System ===\n")
    print("Get a first set of coordinates")
    t = True
    while t:
        co = input("Enter new coordinates as floats in format ’x,y,z’:  ")
        try:
            if ',' not in co:
                raise ValueError("Invalid syntax")
            temp = co.split(',')
            x = float(temp[0].strip())
            y = float(temp[1].strip())
            z = float(temp[2].strip())
            t = False
        except ValueError as e:
            print(e)
    t1 = (x, y, z)
    print(f"Got a first tuple:  {t1}")
    print(f"It includes: X={t1[0]}, Y={t1[1]}, Z={t1[2]}")
    print(f"Distance to center:  {dis(0, 0, 0, t1[0], t1[1], t1[2]):.4f}\n")
    print("Get a second set of coordinates")
    t = True
    while t:
        co = input("Enter new coordinates as floats in format ’x,y,z’:  ")
        if ',' not in co:
            raise ValueError("Invalid syntax")
        try:
            temp = co.split(',')
            x = float(temp[0].strip())
            y = float(temp[1].strip())
            z = float(temp[2].strip())
            t = False
        except ValueError as e:
            print(f"Error on parameter : {e}")
    t2 = (x, y, z)
    print(f"Distance between the 2 sets of coordinates:  "
          f"{dis(t1[0], t1[1], t1[2], t2[0], t2[1], t2[2]):.4f}\n")
