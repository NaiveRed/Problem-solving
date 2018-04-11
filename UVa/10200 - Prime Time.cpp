#include <cstdio>
#define M 10005

bool sieve[M] = {true, true};
int prime[3000], p_idx;
inline bool check(int &&n)
{
    if (n < M)
        return !sieve[n];

    for (int i = 0; i < p_idx; ++i)
        if (!(n % prime[i]))
            return n == prime[i];

    return true;
}

int main()
{
    //freopen("test.out", "w", stdout);
    //linear sieve
    for (int i = 2; i < M; ++i)
    {
        if (!sieve[i])
            prime[p_idx++] = i;

        for (int j = 0; prime[j] * i < M; j++)
        {
            sieve[prime[j] * i] = true;
            if (!(i % prime[j]))
                break;
        }
    }

    int count[10001] = {1}; //0+0+41
    for (int i = 1; i < 40; ++i)
        count[i] = count[i - 1] + 1;
    for (int i = 40; i < 10001; ++i)
    {
        count[i] = count[i - 1];
        if (check(i * i + i + 41))
            ++count[i];
    }

    int a, b;
    while (scanf("%d%d", &a, &b) != EOF)
    {
        int tmp = count[b] - count[a ? (a - 1) : 0] + (a ? 0 : 1); //特別注意 a = 0 的情形
        printf("%.2lf\n", (double)tmp / (b - a + 1) * 100 + 0.0000001);
    }

    return 0;
}