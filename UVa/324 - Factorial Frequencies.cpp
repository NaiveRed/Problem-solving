#include <cstdio>
#define N 800

int main()
{
    int fac[367][N] = {{1}, {1}}, idx = 0;

    for (int i = 2; i < 367; i++)
    {
        for (int j = 0; j <= idx; j++)
            fac[i][j] = fac[i - 1][j] * i;

        for (int j = 0; j <= idx; j++)
            if (fac[i][j] >= 10)
            {
                int carry = fac[i][j] / 10;
                fac[i][j] %= 10;
                fac[i][j + 1] += carry;
                if (j == idx)
                    idx++;
            }
    }

    int n;
    while (scanf("%d", &n) && n)
    {
        int num[10] = {}, i;
        for (i = idx; i >= 0; i--)
            if (fac[n][i])
                break;

        for (; i >= 0; i--)
            num[fac[n][i]]++;

        printf("%d! --\n   ", n);
        for (i = 0; i < 5; i++)
            printf("(%d)%5d    ", i, num[i]);
        printf("\n   ");
        for (; i < 10; i++)
            printf("(%d)%5d    ", i, num[i]);
        putchar('\n');
    }

    return 0;
}