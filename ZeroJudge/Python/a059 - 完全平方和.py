table = [False] * 1001
for i in range(0, 32):
    if i * i > 1000:
        break
    table[i * i] = True

case = int(input())
for c in range(1, case + 1):

    a = int(input())
    b = int(input())
    sum = 0
    for i in range(a, b + 1):
        if table[i]:
            sum += i
    print("Case {0}: {1}".format(c, sum))
