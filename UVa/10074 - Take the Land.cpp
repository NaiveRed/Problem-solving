#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 101

int main()
{
    int m, n, board[N][N];
    int length[N][N] = {};
    while (scanf("%d%d", &m, &n) && (m || n))
    {
        for (int i = 1; i <= m; ++i)
            for (int j = 1; j <= n; ++j)
                scanf("%d", &board[i][j]);

        //1d
        for (int i = 1; i <= m; ++i)
        {
            memset(length[i], 0, sizeof length[i]);
            for (int j = 1; j <= n; ++j)
                if (!board[i][j])
                    length[i][j] = length[i][j - 1] + 1;
        }

        //2d
        int ans = 0;
        for (int i = 1; i <= m; ++i)
            for (int j = 1; j <= n; ++j)
            {
                int local = 1e9;
                for (int k = i; k; k--)
                {
                    if (board[k][j])
                        break;

                    local = std::min(local, length[k][j]);
                    ans = std::max(ans, local * (i - k + 1));
                }
            }

        printf("%d\n", ans);
    }

    return 0;
}