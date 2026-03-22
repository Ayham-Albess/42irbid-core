import sys
import math

def dis(x1: int, y1: int, z1: int
        ,x2: int, y2: int, z2: int):
    return(math.sqrt((x2 - x1)**2 + (y2 - y1)**2 + (z2 - z1)**2))

if __name__ == "__main__":
    print("=== Game Coordinate System ===\n")
    t0 = (0, 0, 0)
    t1 = (10, 20, 5)
    print(f"Position created:  {t1}")
    print(f"Distance between {t0} and {t1}:  {dis(0, 0, 0, 10, 20, 5):.2f}\n")
    t2 = (3, 4, 0)
    print(f"Parsing coordinates:  \"{t2[0]},{t2[1]},{t2[2]}\"")
    print(f"Parsed position:  {t2}")
    print(f"Distance between {t0} and {t2}:  {dis(0, 0, 0, 3, 4, 0):.1f}\n")
    try:
        t4 = ("abd", "def", "ghi")
        print("Parsing invalid coordinates:  \"{t4[0]},{t4[1]},{t4[3]}\"")
        x = int(t4[1])
    except ValueError:
        print("Error parsing coordinates: invalid literal for int() with base 10: ’abc’")



