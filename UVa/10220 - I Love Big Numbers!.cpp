#include<cstdio>

int main()
{
    static int factorial[1001][5000] = { { 0 }, { 1 } };
    int i, j, idx = 0, ans[1001] = { 0, 1 };

    for (i = 2; i < 1001; i++)
    {
        for (j = 0; j <= idx; j++)
            factorial[i][j] = factorial[i - 1][j] * i;

        for (j = 0; j <= idx; j++)
        {
            if (factorial[i][j] >= 10)
            {
                int temp = factorial[i][j] / 10;
                factorial[i][j] %= 10;
                factorial[i][j + 1] += temp;

                if (j == idx)//記目前總位數
                    idx++;
            }

            ans[i] += factorial[i][j];
        }
    }

    int n;
    while (scanf("%d", &n) != EOF)
        printf("%d\n", ans[n]);

    return 0;
}