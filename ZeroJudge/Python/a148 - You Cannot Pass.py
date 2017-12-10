while True:
    try:
        num = input().split()
        sum = 0
        for n in num[1:]:
            sum += int(n)
        print("no" if sum / int(num[0]) > 59 else "yes")
    except:
        break
