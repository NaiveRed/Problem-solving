while True:
    try:
        line = input()
        ans = str("")
        for i in range(1, 7):
            ans += chr(ord("0") + abs(ord(line[i]) - ord(line[i - 1])))
        print(ans)
    except:
        break
