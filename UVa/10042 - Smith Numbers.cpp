#include<cstdio>
#define SQRTN 320
#define N 100000

bool sieve[N] = { true,true };
int prime[10000];
int getPrime()
{
    for (int i = 2; i < SQRTN; i++)
    {
        if (!sieve[i])
            for (int j = i + i; j < N; j += i)
                sieve[j] = true;
    }

    int count = 0;
    for (int i = 0; i < N; i++)
        if (!sieve[i])
            prime[count++] = i;

    return count;
}
inline int digits_sum(int n)
{
    int sum = 0;
    while (n)
    {
        sum += n % 10;
        n /= 10;
    }

    return sum;
}
int main()
{
    int P = getPrime();

    int Case;
    scanf("%d", &Case);
    while (Case--)
    {
        int ans, sum = 0, fsum = -1;
        scanf("%d", &ans);

        while (fsum != sum)
        {
            int n = ++ans, i;
            sum = digits_sum(ans);
            fsum = 0;

            if (n < N && !sieve[n])//n is prime
                continue;

            for ( i = 0; i < P&&prime[i] * prime[i] <= n; i++)
            {
                if (!(n%prime[i]))
                {
                    int ds = digits_sum(prime[i]);//因數的各位數總和
                    while (!(n%prime[i]))
                    {
                        n /= prime[i];
                        fsum += ds;
                    }
                }
            }

            if (ans == n)//ans is prime
                continue;

            if (n != 1)//n 剩下的是質數
                fsum += digits_sum(n);

        }

        printf("%d\n", ans);
    }

    return 0;
}