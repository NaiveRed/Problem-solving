#include <cstdio>
#include <cstdlib>
#define MIN(a, b) ((a) < (b) ? (a) : (b))

int main()
{
    int W, H, N;
    while (scanf("%d%d%d", &W, &H, &N) && (W || H || N))
    {
        bool area[501][501] = {};
        int x1, y1, x2, y2;
        for (int i = 0; i < N; i++)
        {
            scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
            int x = MIN(x1, x2), y = MIN(y1, y2); //最左下角
            int dis_x = abs(x1 - x2), dis_y = abs(y1 - y2);

            for (int i = 0; i <= dis_x; i++)
                for (int j = 0; j <= dis_y; j++)
                    area[x + i][y + j] = true;
        }
        int tot = 0;
        for (int i = 1; i <= W; i++)
            for (int j = 1; j <= H; j++)
                tot += !area[i][j];
        
        if (!tot)
            puts("There is no empty spots.");
        else if (tot == 1)
            puts("There is one empty spot.");
        else
            printf("There are %d empty spots.\n", tot);
    }

    return 0;
}