#include<cstdio>
#include<cmath>
#define N 1000000
#define M 100000

bool sieve[N] = { true, true };
int prime[M], digit_prime[M], ans[N];
int main()
{
    int i, j, k;
    int m = sqrt(N), count = 0;
    //建質數表
    for (i = 2; i <= m; i++)
    {
        if (!sieve[i])
            for (j = i << 1; j < N; j += i)
                sieve[j] = true;
    }
    for (i = 2; i < N; i++)
        if (!sieve[i])
            prime[count++] = i;

    k = 0;
    //建 digit prime
    for (i = 0; i < count; i++)
    {
        int sum = 0, temp = prime[i];
        while (temp)
        {
            sum += temp % 10;
            temp /= 10;
        }
        if (!sieve[sum])
            digit_prime[k++] = prime[i];
    }

    j = count = 0;
    //0 ~ i 有多少個 digit prime
    for (i = 1; i < N; i++)
    {
        if (i == digit_prime[j])
            count++, j++;

        ans[i] = count;
    }

    int Case;
    //I/O
    scanf("%d", &Case);
    while (Case--)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        printf("%d\n", ans[b] - ans[a-1]);//有包含a,b
    }

    return 0;
}