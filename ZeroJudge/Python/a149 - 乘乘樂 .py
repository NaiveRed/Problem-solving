n = int(input())
while n > 0:
    n -= 1
    num = input()
    sum = 1
    for c in num:
        sum *= int(c)
    if num == "0":
        print("0")
    else:
        print(sum)
