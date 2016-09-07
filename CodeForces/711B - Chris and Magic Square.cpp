#include<cstdio>
typedef long long LL;

int main()
{
    int n, i, j, r, c;
    static LL grid[500][500];
    scanf("%d", &n);

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
        {
            scanf("%I64d", &grid[i][j]);
            if (!grid[i][j])
            {
                r = i;
                c = j;
            }
        }

    if (n == 1)
    {
        puts("1");
        return 0;
    }

    LL tar = 0, x = 0;
    bool ans = true;

    for (i = 0; i < n; i++)
        tar += grid[r ? 0 : 1][i];

    for (i = 0; i < n; i++)
        x += grid[r][i];

    grid[r][c] = tar - x;

    if (grid[r][c] > 0)
    {
        LL sum;
        //row
        for (i = 0; i < n; i++)
        {
            sum = 0;
            for (j = 0; j < n; j++)
                sum += grid[i][j];
            if (sum != tar)
            {
                ans = false;
                break;
            }
        }

        //column
        for (i = 0; i < n; i++)
        {
            sum = 0;
            for (j = 0; j < n; j++)
                sum += grid[j][i];
            if (sum != tar)
            {
                ans = false;
                break;
            }
        }

        //dia
        sum = 0;
        for (i = 0; i < n; i++)
            sum += grid[i][i];
        if (sum != tar)
            ans = false;
        sum = 0;
        for (i = 0; i < n; i++)
            sum += grid[i][n - i - 1];
        if (sum != tar)
            ans = false;
    }
    else
        ans = false;

    if (ans)
        printf("%I64d\n", grid[r][c]);
    else
        puts("-1");

    return 0;
}