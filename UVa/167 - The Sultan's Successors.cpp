#include<cstdio>
#define N 8

bool mx[N];
bool s1[15], s2[15];//斜線右上到左下,左上到右下
int ans[N],table[100][N];
int build(int col)
{
    static int count = 0;//總共92種

    if (col == N)
    {
        for (int i = 0; i < N; i++)
            table[count][i] = ans[i];
        count++;
    }
    else
        for (int x = 0; x < N; x++)//col 行的第 x 列 
        {
            int d1 = x + col, d2 = col - x + 7;
            if (!mx[x] && !s1[d1] && !s2[d2])
            {
                mx[x] = s1[d1] = s2[d2] = true;
                ans[col] = x;
                build(col + 1);
                mx[x] = s1[d1] = s2[d2] = false;
            }
        }

    return count;
}
int main()
{
    int kind = build(0), Case, map[N][N];
    scanf("%d", &Case);
    while (Case--)
    {
        int i, j;
        for (i = 0; i < N; i++)
            for (j = 0; j < N; j++)
                scanf("%d", &map[i][j]);

        int sum, max = 0;
        for (i = 0; i < kind; i++)
        {
            sum = 0;
            for (j = 0; j < N; j++)
                sum += map[j][table[i][j]];
            if (sum > max)
                max = sum;
        }

        printf("%5d\n", max);
    }

    return 0;
}