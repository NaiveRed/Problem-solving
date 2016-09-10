#include<cstdio>

int main()
{
    int ans[4][10], count[4] = {};
    int div[4] = { 10,100,1000,10000 };

    for (int i = 0; i < 10000; i++)
    {
        int square = i*i;
        for (int j = 0; j < 4; j++)
        {
            if (i < div[j])//總位數就不會是 n 了, 10 * 10 = 100 ,100 為 3 位數。
            {
                int x = square / div[j] + square%div[j];
                if (x == i)
                    ans[j][count[j]++] = square;
            }
        }
    }

    int n;
    while (scanf("%d", &n) != EOF)
    {
        int idx = n / 2 - 1;
        for (int i = 0; i < count[idx]; i++)
            printf("%0*d\n", n, ans[idx][i]);
    }

    return 0;
}