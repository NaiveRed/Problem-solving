#include<cstdio>
#define N 500
#define MAX 1000000

int main()
{
    int d[N][N] = {}, max;
    int n, i, j, k, Case;
    scanf("%d", &Case);

    while (Case--)
    {
        scanf("%d", &n);
        getchar();
        char c;

        for (i = 0; i < n; i++)
            for (j = 0; j < n; j++)
                d[i][j] = 1e9;

        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                c = getchar();
                if (c == '1')
                    d[i][j] = 1;
            }
            getchar();
        }

        for (i = 0; i < n; i++)
            d[i][i] = 0;

        for (k = 0; k < n; k++)
            for (i = 0; i < n; i++)
                for (j = 0; j < n; j++)
                    if (d[i][k] + d[k][j] < d[i][j])
                        d[j][i] = d[i][j] = d[i][k] + d[k][j];

        bool flag = true;
        max = 0;
        for (i = 0; i < n&&flag; i++)
            for (j = 0; j < n; j++)
                if (max < d[i][j])
                    max = d[i][j];
                else if (d[i][j] == 1e9)
                {
                    flag = false;
                    break;
                }

        if (flag)
            printf("%d\n", max);
        else
            puts("-1");
    }

    return 0;
}