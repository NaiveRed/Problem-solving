#include<cstdio>
#include<cmath>
#define N 100000
#define M 50000

int prime[M];
bool sieve[N]{ true, true };

inline void getPrime();
int main()
{
    getPrime();
    int Case;
    scanf("%d", &Case);

    while (Case--)
    {

        int a, b;
        int max = 0, max_count = 0;

        scanf("%d%d", &a, &b);
        for (int i = a; i <= b; i++)
        {
            int total = 1, temp = i;

            for (int j = 0; prime[j] && prime[j] * prime[j] <= temp; j++)
            {
                int count(0);
                while (!(temp%prime[j]))
                {
                    temp /= prime[j];
                    count++;
                }

                total *= (count + 1);
            }

            if (temp != 1)
                total <<= 1;

            if (total > max_count)
            {
                max_count = total;
                max = i;
            }
        }

        printf("Between %d and %d, %d has a maximum of %d divisors.\n", a, b, max, max_count);

    }
    return 0;
}
inline void getPrime()
{
    int _sqrt = sqrt(N - 1);

    for (int i = 2; i < _sqrt; i++)
    {

        if (!sieve[i])
            for (int k = (N - 1) / i; k >= i; k--)
                if (!sieve[k])
                    sieve[k*i] = true;
    }

    int count(0);
    for (int i = 0; i < N; i++)
    {
        if (!sieve[i])
            prime[count++] = i;
    }
}