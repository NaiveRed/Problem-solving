table = dict()
order = "ABCDEFGHJKLMNPQRSTUVXYWZIO"
for i in range(10, 36):
    table[order[i - 10]] = i

while True:
    try:
        line = input()
        sum = int(line[-1])
        j = 8
        for n in line[:-1]:
            sum += int(n) * j
            j -= 1
        for c in "ABCDEFGHIJKLMNOPQRSTUVWXYZ":
            temp = table[c] // 10 + (table[c] % 10) * 9
            if (sum + temp) % 10 == 0:
                print(c, end="")
        print("")
    except:
        break
