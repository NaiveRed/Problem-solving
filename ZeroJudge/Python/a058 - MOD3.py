n = int(input())
ans = [0, 0, 0]
for i in range(0, n):
    ans[int(input()) % 3] += 1
print(ans[0], ans[1], ans[2])
