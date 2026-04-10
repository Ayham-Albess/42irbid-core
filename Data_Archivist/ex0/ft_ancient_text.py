import sys

if __name__ == "__main__":
    if len(sys.argv) == 1:
        print("Usage:  ft_ancient_text.py <file>")
    else:
        try:
            print("=== Cyber Archives Recovery ===")
            print(f"Accissing file '{sys.argv[1]}'")
            f = open(sys.argv[1], 'r')
            print("---\n")
            for i in f:
                print(i)
            print("\n---")
            f.close()
            print(f"File {sys.argv[1]} closed")
        except (FileNotFoundError, PermissionError) as e:
            print(f"Error opening file '{sys.argv[1]}':  {e}")
