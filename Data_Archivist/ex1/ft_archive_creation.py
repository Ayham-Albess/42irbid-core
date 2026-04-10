import sys

if __name__ == "__main__":
    ar = []
    if len(sys.argv) == 1:
        print("Usage:  ft_archive_creation.py <file>")
    else:
        try:
            print("=== Cyber Archives Recovery & Preservation ===")
            print(f"Accissing file '{sys.argv[1]}'")
            f = open(sys.argv[1], 'r')
            print("---\n")
            for i in f:
                i = i.rstrip('\n')
                ar += [i]
                print(i)
            print("\n---")
            f.close()
            print(f"File {sys.argv[1]} closed\n")
        except (FileNotFoundError, PermissionError) as e:
            print(f"Error opening file '{sys.argv[1]}':  {e}")
        print("Transform data:\n---\n")
        j = 0
        for i in ar:
            i += '#'
            ar[j] = i
            j += 1
            print(i)
        print("---\n")
        s = input("Enter new file name (or empty):  ")
        if s 
