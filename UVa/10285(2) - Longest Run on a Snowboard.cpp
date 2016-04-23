#include<cstdio>
#define N 101
#define IN(x,y,bx,by) (x&&x<=bx&&y&&y<=by)
using namespace std;

int grid[N][N];
int dp[N][N];
const int dir[4][2] = { { 1, 0 }, { -1, 0 }, { 0, -1 }, { 0, 1 } };
int row, col;
void dfs(int x, int y);
int main()
{
    int Case;
    scanf("%d", &Case);

    char name[100];
    while (Case--)
    {
        int i, j;

        scanf("%s%d%d", name, &row, &col);
        for (i = 1; i <= row; i++)
            for (j = 1; j <= col; j++)
            {
            scanf("%d", &grid[i][j]);
            dp[i][j] = 1;
            }

        int ans = 0;
        for (i = 1; i <= row; i++)
            for (j = 1; j <= col; j++)
                dfs(i, j);

        for (i = 1; i <= row; i++)
            for (j = 1; j <= col; j++)
                if (ans < dp[i][j])
                    ans = dp[i][j];

        printf("%s: %d\n", name, ans);
    }

    return 0;
}
void dfs(int x, int y)
{
    for (int i = 0; i < 4; i++)
    {
        int next_x = x + dir[i][0], next_y = y + dir[i][1];
        if (IN(next_x, next_y, row, col) && grid[next_x][next_y] < grid[x][y] && dp[next_x][next_y] < dp[x][y] + 1)
        {
            dp[next_x][next_y] = dp[x][y] + 1;
            dfs(next_x, next_y);
        }
    }
}
