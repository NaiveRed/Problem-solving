while True:
    try:
        line = input().split()
        total = n = int(line[0])
        m = int(line[1])
        count = 1
        while total <= m:
            n += 1
            count += 1
            total += n
        print(count)
    except:
        break

# -3 -3
# 7
