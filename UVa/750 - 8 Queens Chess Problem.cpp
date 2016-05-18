//http://www.csie.ntnu.edu.tw/~u91029/Backtracking.html#4
#include<cstdio>
#define N 8

int ans[N] = {}, kind, must;//第 x 行的皇后在第 ans[x] 列
bool mx[N];
bool s1[15], s2[15];//右上到左下,左上到右下
void solve(int row, int col);
void backtracking(int col, int count);
int main()
{
    int Case;
    scanf("%d", &Case);
    while (Case--)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        puts("SOLN       COLUMN");
        puts(" #      1 2 3 4 5 6 7 8\n");

        for (int i = 0; i < N; i++)
        {
            mx[i] = false;
            ans[i] = -1;
        }
        for (int i = 0; i < 15; i++)
            s1[i] = s2[i] = false;

        solve(x, y);

        if (Case)
            putchar('\n');
    }
    return 0;
}
void solve(int row, int col)
{
    kind = 0;
    //方便計算，最左上為 (0,0)
    row--;
    col--;
    mx[row] = s1[row + col] = s2[col - row + 7] = true;
    ans[col] = row;
    must = col;
    backtracking(0, 0);
}
void backtracking(int col, int count)//每次都換不同行
{
    if (count == N)
    {
        kind++;
        printf("%2d     ", kind);
        for (int i = 0; i < N; i++)
            printf(" %d", ans[i] + 1);
        putchar('\n');
        return;
    }
    else if (col == must)//指定的
        backtracking(col + 1, count + 1);
    else
    {
        for (int x = 0; x < N; x++)
        {
            int d1 = x + col, d2 = col - x + 7;//找出他們在第幾條斜線(這邊兩個方向的取法不一樣)
            if (!mx[x] && !s1[d1] && !s2[d2])
            {
                mx[x] = s1[d1] = s2[d2] = true;

                ans[col] = x;
                backtracking(col + 1, count + 1);

                mx[x] = s1[d1] = s2[d2] = false;
            }
        }
    }
}