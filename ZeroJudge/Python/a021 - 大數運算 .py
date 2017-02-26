while True:
    try:
        line = input().split()
        a = int(line[0])
        b = int(line[2])
        op = line[1]
        ans = None
        if op == '+':
            ans = a + b
        elif op == '-':
            ans = a - b
        elif op == '*':
            ans = a * b
        elif op == '/':
            ans = a // b
        print(ans)
    except:
        break
