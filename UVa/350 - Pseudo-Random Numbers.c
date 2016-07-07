#include<stdio.h>
#define N 10000

int main()
{
    int Z, I, L, M, Case = 1;
    int num[N];//num 用來記數字出現的順序

    while (scanf("%d%d%d%d", &Z, &I, &M, &L) && M)
    {
        int i, count = 0;
        for (i = 0; i < N; i++)
            num[i] = 0;

        while (!num[L])
        {
            num[L] = ++count;
            L = (Z*L + I) % M;
        }

        printf("Case %d: %d\n", Case++, count - num[L] + 1);
    }

    return 0;
}