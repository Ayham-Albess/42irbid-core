import sys

if __name__ == "__main__":
    print("=== Command Quest ===")
    if len(sys.argv) == 1:
        print("No arguments provided!")
        print(f"Program name:  {sys.argv[0]}")
        print("Total arguments: 1")
    else:
        print(f"Program name:  {sys.argv[0]}")
        print(f"Arguments received:  {len(sys.argv) - 1}")
        i = 1
        while i < len(sys.argv):
            print(f"Argument {i}:  {sys.argv[i]}")
            i += 1
        print(f"Total arguments:  {i + 1}")
