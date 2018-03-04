#include <cstdio>
#include <cmath>
#define N 18409545

int main()
{
    //freopen("test.in","r",stdin);
    //freopen("test.out","w",stdout);
    static bool sieve[N] = {true, true}; //18409541 最後一對
    int _sqrt = sqrt(N);

    for (int i = 2; i <= _sqrt; i++)
    {
        if (!sieve[i])
        {
            for (int k = (N - 1) / i; k >= i; k--)
                if (!sieve[k])
                    sieve[k * i] = true;
        }
    }

    //twin primes
    int idx[100000] = {};
    for (int i = 2, j = 0; i < N && j < 100000; i++)
    {
        if (!sieve[i] && !sieve[i + 2])
            idx[j++] = i;
    }

    int s;
    while (scanf("%d", &s) != EOF)
        printf("(%d, %d)\n", idx[s - 1], idx[s - 1] + 2);

    return 0;
}