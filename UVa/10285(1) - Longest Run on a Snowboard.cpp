#include<cstdio>
#define MAX(a,b) ((a)>(b)?(a):(b))
#define N 102
using namespace std;

int grid[N][N];
int dp[N][N];//���I�i�����̻��Z��
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

        //��ɳB�z
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
int dfs(int x, int y)//�^�Ǧ��I�i�����̻��Z��
{
    //�H���I���_�I���w�g���L�F
    if (dp[x][y])
        return dp[x][y];

    dp[x][y] = 1;//�ۤv�]�]�t�b��
    
    //�P�_���W�U���k�A���ӥi�����
    for (int i = 0; i < 4; i++)
    {
        int next_x = x + dir[i][0], next_y = y + dir[i][1];
        if (grid[next_x][next_y] < grid[x][y])
            dp[x][y] = MAX(dfs(next_x, next_y) + 1, dp[x][y]);
    }

    return dp[x][y];
}