f = [0]
g = [0]

for i in range(1, 30001):
    f.append(i + f[i - 1])
    g.append(g[i - 1] + f[i])

while True:
    try:
        n = int(input())
        print(f[n], g[n], sep=" ")
    except:
        break
