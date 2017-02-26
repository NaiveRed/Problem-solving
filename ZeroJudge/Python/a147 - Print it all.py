seven = [i for i in range(1, 10001) if i % 7 != 0]

while True:
    n = int(input())
    if n == 0:
        break
    first = True
    for i in seven:
        if i >= n:
            break
        if not first:
            print(" ", end="")
        else:
            first = False
        print(i, end="")
    print("")
