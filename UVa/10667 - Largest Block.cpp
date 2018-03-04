//http://www.csie.ntnu.edu.tw/~u91029/MaximumSubarray.html#2
#include <cstdio>
#include <cstring>
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define N 101

int main()
{
    int Case;
    bool board[N][N] = {};
    int length[N][N] = {};
    scanf("%d", &Case);
    while (Case--)
    {
        int s, n, r1, r2, c1, c2;
        scanf("%d%d", &s, &n);
        for (int i = 0; i < n; ++i)
        {
            scanf("%d%d%d%d", &r1, &c1, &r2, &c2);
            for (int r = r1; r <= r2; ++r)
                for (int c = c1; c <= c2; ++c)
                    board[r][c] = true;
        }

        //1d
        for (int r = 1; r <= s; ++r)
        {
            memset(length[r], 0, sizeof length[r]);
            for (int c = 1; c <= s; ++c)
                if (!board[r][c])
                    length[r][c] = length[r][c - 1] + 1;
        }

        //窮舉矩形右下頂點
        int max = 0;
        for (int r = 1; r <= s; ++r)
            for (int c = 1; c <= s; ++c)
            {
                int w = 1e9;
                for (int k = r; k; --k)
                    if (board[k][c])
                        break;
                    else
                    {
                        w = MIN(w, length[k][c]);
                        max = MAX(max, w * (r - k + 1));
                    }
            }

        printf("%d\n", max);

        //init
        for (int i = 0; i <= s; i++)
            memset(board[i], false, sizeof board[i]);
    }

    return 0;
}