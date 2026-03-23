import math


def dis(x1: int, y1: int, z1: int,
        x2: int, y2: int, z2: int):
    return (math.sqrt((x2 - x1)**2 + (y2 - y1)**2 + (z2 - z1)**2))


if __name__ == "__main__":
    print("=== Game Coordinate System ===\n")
    t0 = (0, 0, 0)
    t1 = (10, 20, 5)
    print(f"Position created:  {t1}")
    print(f"Distance between {t0} and {t1}:  {dis(0, 0, 0, 10, 20, 5):.2f}\n")
    t2 = "3,4,0"
    print(f"Parsing coordinates:  {t2}")
    coordinates = ()
    temp = []
    for a in t2:
        if a != ',':
            temp += [int(a)]
    coor = tuple(temp)
    print(f"Parsed position:  {coor}")
    print(f"Distance between {t0} and {coor}:",
          f"  {dis(0, 0, 0, 3, 4, 0):.1f}\n")
    try:
        t4 = ("abd", "def", "ghi")
        temp = []
        coordinates2 = ()
        print(f"Parsing invalid coordinates:  \"{t4[0]},{t4[1]},{t4[2]}\"")
        for a in t4:
            temp += [int(a)]
        coordinates2 = tuple(t4)
    except ValueError as e:
        print(f"Error parsing coordinates:  {e}")
        print(f"Error details - Type:  ValueError, Args:  (\"{e}\",)\n")
    print("Unpacking demonstration:")
    print(f"Player at x={coor[0]}, y={coor[1]}, z={coor[2]}")
    print(f"Coordinates:  X={coor[0]}, Y={coor[1]}, Z={coor[2]}")
