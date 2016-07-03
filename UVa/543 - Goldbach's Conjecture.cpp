#include<cstdio>
#include<cmath>
#define N 1000000

int main()
{
    bool sieve[N] = {1,1};
    int SQRT = sqrt(N);
    for (int i = 2; i <= SQRT; i++)
        if (!sieve[i])
            for (int j = i << 1; j < N; j += i)
                sieve[j] = true;

    int n;
    while (scanf("%d", &n) && n)
    {
        int half = n >> 1;
        for (int i = 2;i<=half;i++)
            if (!sieve[i] && !sieve[n - i])
            {
            printf("%d = %d + %d\n", n, i, n - i);
            break;
            }
    }

    return 0;
}