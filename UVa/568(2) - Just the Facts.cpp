/*
可以在 UVa AC 但對於 9537 似乎會由於精度不足有誤
9375 -> 3
正解:
9375 -> 8
*/
#include <cstdio>
#define N 10001
#define M 100000
int main()
{
    int fact[N] = {1, 1};
    for (int i = 2; i < N; i++)
    {
        fact[i] = i * fact[i - 1];
        while (!(fact[i] % 10))
            fact[i] /= 10;

        fact[i] %= M;
    }

    int n;
    while (scanf("%d", &n) != EOF)
        printf("%5d -> %d\n", n, fact[n] % 10);

    return 0;
}