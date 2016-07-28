#include<cstdio>

int n, count, max;
char board[6][6];
bool rook[6][6];
inline bool isOk(int r, int c)
{
    int i;
    for (i = r; board[i][c] && board[i][c] != 'X'; i--)
        if (rook[i][c])
            return false;
    for (i = r; board[i][c] && board[i][c] != 'X'; i++)
        if (rook[i][c])
            return false;
    for (i = c; board[r][i] && board[r][i] != 'X'; i--)
        if (rook[r][i])
            return false;
    for (i = c; board[r][i] && board[r][i] != 'X'; i++)
        if (rook[r][i])
            return false;

    return true;
}
void dfs(int r);
int main()
{
    while (scanf("%d", &n) && n)
    {
        getchar();
        int i, j;
        for (i = 0; i <= n + 1; i++)
            board[i][0] = board[0][i] = NULL;

        for (i = 1; i <= n; i++)
        {
            for (j = 1; j <= n; j++)
                board[i][j] = getchar();
            getchar();
        }

        for (i = 1; i <= n; i++)
            for (j = 1; j <= n; j++)
                rook[i][j] = false;

        count = max = 0;
        dfs(1);
        printf("%d\n", max);
    }

    return 0;
}
void dfs(int r)
{
    for (; r <= n; r++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (board[r][j] != 'X'&&isOk(r, j))//可以放才繼續做下去
            {
                rook[r][j] = true;
                count++;

                dfs(r);

                rook[r][j] = false;
                count--;
            }
        }
    }

    if (r > n)
        max = max > count ? max : count;
}