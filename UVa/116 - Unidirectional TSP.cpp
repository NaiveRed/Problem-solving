#include<cstdio>
#define M 10
#define N 100

inline int MIN(int a, int b);
int main()
{
    int n, m;
    int  map[M][N] = {}, path[M][N] = {}, dis[M][N] = {};
    while (scanf("%d%d", &m, &n) != EOF)
    {
        int i, j;
        for (i = 0; i < m; i++)
            for (j = 0; j < n; j++)
                scanf("%d", &map[i][j]);

        for (i = 0; i < m; i++)
            for (j = 0; j < n; j++)
                dis[i][j] = 1e9;

        //初始化 到最後一行 的 dis
        for (i = 0; i < m; i++)
            dis[i][n - 1] = map[i][n - 1];

        //從右邊開始走到 (j,i) 的最短路
        for (i = n - 2; i >= 0; i--)//col
        {
            for (j = 0; j < m; j++)//row
            {
                int a, b, c, temp, min;

                //3 種走法
                a = (j + m - 1) % m;
                b = j;
                c = (j + 1) % m;

                //找最短路
                temp = MIN(dis[a][i + 1], dis[b][i + 1]);
                if (temp == 1)
                    min = a;
                else if (temp == -1)
                    min = b;
                else
                    min = a < b ? a : b;//選字典序小的

                temp = MIN(dis[min][i + 1], dis[c][i + 1]);
                if (temp == -1)
                    min = c;
                else if (!temp)
                    min = min < c ? min : c;//選字典序小的

                //到 (j,i) 的最短路
                dis[j][i] = dis[min][i + 1] + map[j][i];

                //到 (j,i) 最短路的上一點是在第 min 列
                path[j][i] = min;
            }
        }

        int row, min = 1e9;
        //找第一行 dis 最小的，注意字典序
        for (i = 0; i < m; i++)
            if (dis[i][0] < min)
            {
            min = dis[i][0];
            row = i;
            }

        for (i = 0; i < n - 1; i++)
        {
            printf("%d ", row + 1);
            row = path[row][i];
        }

        printf("%d\n%d\n", row + 1, min);
    }

    return 0;
}
int MIN(int a, int b)
{
    if (a < b)
        return 1;
    else if (a > b)
        return -1;
    else
        return 0;
}