while True:
    try:
        ans = 0
        n = int(input())
        if n >= 40:
            ans = 100
        elif n > 20:
            ans += n - 20 + 80
        elif n > 10:
            ans += (n - 10) * 2 + 60
        else:
            ans += n * 6
        print(ans)
    except:
        break
