#include<cstdio>
#define MAX(a,b) ((a)>(b)?(a):(b))
#define N 102
using namespace std;

int grid[N][N];
int dp[N][N];//此點可走的最遠距離
const int dir[4][2] = { { 1, 0 }, { -1, 0 }, { 0, -1 }, { 0, 1 } };
int dfs(int x, int y);
int main()
{
    int i, j;

    int Case;
    scanf("%d", &Case);

    char name[100];
    while (Case--)
    {
        int row, col;
        scanf("%s%d%d", name, &row, &col);

        //邊界處理
        for (i = 0; i <= col + 1; i++)
            grid[0][i] = grid[row + 1][i] = 1000;
        for (i = 0; i <= row + 1; i++)
            grid[i][0] = grid[i][col + 1] = 1000;

        for (i = 1; i <= row; i++)
            for (j = 1; j <= col; j++)
            {
            scanf("%d", &grid[i][j]);
            dp[i][j] = 0;
            }

        int ans = 0;
        for (i = 1; i <= row; i++)
            for (j = 1; j <= col; j++)
                ans = MAX(dfs(i, j), ans);

        printf("%s: %d\n", name, ans);
    }

    return 0;
}
int dfs(int x, int y)//回傳此點可走的最遠距離
{
    //以此點為起點的已經做過了
    if (dp[x][y])
        return dp[x][y];

    dp[x][y] = 1;//自己也包含在內
    
    //判斷走上下左右，哪個可比較遠
    for (int i = 0; i < 4; i++)
    {
        int next_x = x + dir[i][0], next_y = y + dir[i][1];
        if (grid[next_x][next_y] < grid[x][y])
            dp[x][y] = MAX(dfs(next_x, next_y) + 1, dp[x][y]);
    }

    return dp[x][y];
}