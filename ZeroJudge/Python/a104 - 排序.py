while True:
    try:
        n = int(input())
        line = input().split()
        # num = sorted([int(x) for x in line])
        num = sorted(line, key=int)
        for i in num[:-1]:
            print(i, end=" ")
        print(num[n - 1])
    except:
        break
