//Goldbach's Conjecture
#include<cstdio>
#include<cmath>
#define N 10000000

int main()
{
    static bool sieve[N] = { 1, 1 };
    int SQRT = sqrt(N);
    for (int i = 2; i <= SQRT; i++)
        if (!sieve[i])
            for (int j = i << 1; j < N; j += i)
                sieve[j] = true;

    int n, i;
    while (scanf("%d", &n) != EOF)
    {
        if (n < 8)
        {
            puts("Impossible.");
            continue;
        }

        if (n & 1)
        {
            n -= 5;
            printf("2 3 ");
        }
        else
        {
            n -= 4;
            printf("2 2 ");
        }

        for (i = 2; i < n; i++)
            if (!sieve[i] && !sieve[n - i])
                break;

        printf("%d %d\n", i, n - i);
    }

    return 0;
}