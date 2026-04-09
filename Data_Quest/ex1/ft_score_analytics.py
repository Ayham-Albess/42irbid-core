import sys


def hh(x):
    for i in x:
        if not ('0' <= i <= '9'):
            return False
        return True


if __name__ == "__main__":
    print("=== Player Score Analytics ===")
    if len(sys.argv) == 1:
        print("No scores provided. Usage: python3", end=' ')
        print("ft_score_analytics.py <score1>")
        print("<score2> ...")
    else:
        arr = []
        bb = []
        index = 1
        i = 1
        while i < len(sys.argv):
            if hh(sys.argv[i]):
                arr += [int(sys.argv[i])]
            else:
                bb += [i]
            index += 1
            i += 1
        if not (bb == []):
            for i in bb:
                print(f"Invalid parameter: '{sys.argv[i]}'")
            print("No scores provided. Usage: python3", end=' ')
            print("ft_score_analytics.py <score1>")
            print("<score2> ...")
        else:
            print(f"Scores processed:  {arr}")
            print(f"Total players:  {len(arr)}")
            print(f"Total score:  {sum(arr)}")
            print(f"Average score:  {(sum(arr)/len(arr))}")
            print(f"High score:  {max(arr)}")
            print(f"Low score:  {min(arr)}")
            print(f"Score range:  {max(arr) - min(arr)}")
