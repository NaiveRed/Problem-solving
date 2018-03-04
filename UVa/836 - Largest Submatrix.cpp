#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 105

int main()
{
    int Case;
    scanf("%d ", &Case);

    char board[N][N];
    int length[N][N] = {};
    while (Case--)
    {
        fgets(board[1] + 1, N - 1, stdin); //最左上角為 (1, 1)

        int h = 1, w = strlen(board[1] + 1) - 1;

        while (fgets(board[++h] + 1, N - 1, stdin) && board[h][1] != '\n')
            ;

        h--;
        //1D largest length for each row
        for (int i = 1; i <= h; i++)
        {
            memset(length[i], 0, sizeof length[i]);
            for (int j = 1; j <= w; j++)
                if (board[i][j] == '1')
                    length[i][j] = length[i][j - 1] + 1;
        }

        //2D largest area for each point (取的點當作方形的右下角)
        int ans = 0;
        for (int i = 1; i <= h; i++)
            for (int j = 1; j <= w; j++)
            {
                int local = 1e9;
                for (int k = i; k; k--)
                {
                    if (board[k][j] == '0')
                        break;
                    else
                    {
                        local = std::min(local, length[k][j]);    //往上找，並紀錄最短
                        ans = std::max(ans, local * (i - k + 1)); //計算面積
                    }
                }
            }

        printf("%d\n", ans);
        if (Case)
            putchar('\n');
    }

    return 0;
}