import math


def check(n):
    if n == 1:
        return 0
    S = math.sqrt(n)
    for i in range(0, 1229):  # len(prime)
        if S < prime[i]:
            break
        elif n % prime[i] == 0:
            return 0
    return 1


N = 10000
SQRT = 100
sieve = [True, True] + [False] * (N)
for i in range(2, SQRT + 1):
    if not sieve[i]:
        for k in range(i + i, N + 1, i):
            sieve[k] = True

prime = [i for i in range(2, N + 1) if not sieve[i]]

while True:
    try:
        line = input().split()
        n, m = int(line[0]), int(line[1])
        count = 0
        for i in range(n, m + 1):
            count += check(i)
        print(count)
    except:
        break
