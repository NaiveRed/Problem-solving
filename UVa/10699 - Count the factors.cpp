#include<cstdio>
#include<cmath>
#define N 1001

int main()
{
    //建質數
    bool sieve[N] = { true, true };
    int prime[N], i, sqrt_n = sqrt(N);
    for (i = 2; i <= sqrt_n; i++)
        if (!sieve[i])
            for (int j = i + i; j < N; j += i)
                sieve[j] = true;

    int count = 0;
    for (i = 0; i < N; i++)
    {
        if (!sieve[i])
            prime[count++] = i;
    }

    int n;
    while (scanf("%d", &n) && n)
    {
        int ans = 0, temp = n;
        //因數分解
        for (i = 0; i < count&&n >= prime[i] * prime[i]; i++)
            if (!(n%prime[i]))
            {
            ans++;
            while (!(n%prime[i]))
                n /= prime[i];
            }
        if (n > 1)
            ans++;

        printf("%d : %d\n", temp, ans);
    }

    return 0;
}