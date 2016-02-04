#include<cstdio>
#define N 102

char grid[N][N];
bool isVisit[N][N];
bool dig(int x, int y);//有挖到就 return true
int main()
{
    int m, n, i, j;

    while (scanf("%d%d", &m, &n) && m)
    {
        getchar();
        //input
        for (i = 1; i <= m; i++)
        {
            for (j = 1; j <= n; j++)
                grid[i][j] = getchar();
            getchar();
        }

        //dig
        int count = 0;
        for (i = 1; i <= m; i++)
            for (j = 1; j <= n; j++)
                if (dig(i, j))
                    count++;

        printf("%d\n", count);

        //init
        for (i = 0; i <= m+1; i++)
            for (j = 0; j <= n+1; j++)
            {
            grid[i][j] = NULL;
            isVisit[i][j] = false;
            }
    }

    return 0;
}
bool dig(int x, int y)
{
    if (isVisit[x][y])//已經探查過了
        return false;

    //自己這格
    bool oil = grid[x][y] == '@' ? true : false;
    isVisit[x][y] = true;

    for (int i = x - 1; i <= x + 1; i++)
        for (int j = y - 1; j <= y + 1; j++)
        {
        if (!isVisit[i][j])
        {
            if (grid[i][j] == '@')
            {
                oil = true;
                dig(i, j);
            }
            else
                isVisit[i][j] = true;
        }
        }

    return oil;
}