#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 1025
using namespace std;

int main()
{    
    static int grid[N][N] = {}, kill[N][N] = {};
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int n, d, bottom = 0;
        int lx = N, ly = N, rx = 0, ry = 0; //邊界
        scanf("%d%d", &d, &n);

        for (int i = 0; i < n; ++i)
        {
            int x, y, size;
            scanf("%d%d%d", &x, &y, &size);
            lx = min(lx, x);
            ly = min(ly, y);
            rx = max(rx, x);
            ry = max(ry, y);
            bottom = max(bottom, x); //init 用
            grid[x][y] = size;
        }

        lx = max(0, lx - d);
        ly = max(0, ly - d);
        rx = min(N - 1, rx + d);
        ry = min(N - 1, ry + d);
        for (int x = lx; x <= rx; ++x)
        {
            //初始 window (ly-d~ly+d) 內的值
            int left = max(0, ly - d);
            for (int i = left; i <= ly + d && i < N; ++i)
                kill[x][ly] += grid[x][i];

            //移動 window 並增減頭尾的數字
            for (int i = ly + 1; i <= ry; ++i)
                kill[x][i] = kill[x][i - 1] - ((i - d - 1 >= 0) ? grid[x][i - d - 1] : 0) + ((i + d < N) ? grid[x][i + d] : 0);
        }

        int ans = 0, mx = 0, my = 0;
        for (int x = lx; x <= rx; ++x)
            for (int y = ly; y <= ry; ++y)
            {
                int sum = 0;
                //把炸彈範圍內列的相加
                for (int i = max(0, x - d); i <= x + d; ++i)
                    sum += kill[i][y];
                if (sum > ans)
                {
                    ans = sum;
                    mx = x;
                    my = y;
                }
            }

        printf("%d %d %d\n", mx, my, ans);
        for (int i = lx; i <= rx; ++i)
        {
            memset(grid[i], 0, sizeof grid[i]);
            memset(kill[i], 0, sizeof kill[i]);
        }
    }

    return 0;
}