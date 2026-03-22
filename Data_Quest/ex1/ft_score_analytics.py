import sys

if __name__ == "__main__":
    print("=== Player Score Analytics ===")
    if len(sys.argv) == 1:
        print("No scores provided. Usage: python3", end=' ')
        print("ft_score_analytics.py <score1>")
        print("<score2> ...")
    else:
        arr = []
        try:
            for i in range(1, len(sys.argv)):
                arr += [int(sys.argv[i])]
        except ValueError:
            print("Enter a number Bruh")
        print(f"Scores processed:  {arr}")
        print(f"Total players:  {len(arr)}")
        print(f"Total score:  {sum(arr)}")
        print(f"Average score:  {(sum(arr)/len(arr))}")
        print(f"High score:  {max(arr)}")
        print(f"Low score:  {min(arr)}")
        print(f"Score range:  {max(arr) - min(arr)}")
