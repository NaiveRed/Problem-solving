#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 1025
using namespace std;

inline int get_num()
{
    int n = 0;
    char c;
    while ((c = getchar()) != '\n' && c != ' ' && c != EOF)
        n = n * 10 + c - '0';
    return n;
}
int main()
{    
    static int grid[N][N] = {};
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int n, d;
        int lx = N, ly = N, rx = 0, ry = 0; //邊界
        scanf("%d%d ", &d, &n);

        int mx = 0, my = 0, ans = 0;
        for (int i = 0; i < n; ++i)
        {
            int x, y, size;
            x = get_num();
            y = get_num();
            size = get_num();
            lx = min(lx, x - d);
            ly = min(ly, y - d);
            rx = max(rx, x + d);
            ry = max(ry, y + d);

            int xa = max(0, x - d), ya = max(0, y - d), xb = min(1024, x + d), yb = min(1024, y + d);
            for (int i = xa; i <= xb; ++i)
                for (int j = ya; j <= yb; ++j)
                    grid[i][j] += size; //當炸彈放在 (i, j) 時可消滅的老鼠數量
        }

        lx = max(0, lx);
        ly = max(0, ly);
        rx = min(N - 1, rx);
        ry = min(N - 1, ry);
        for (int x = lx; x <= rx; ++x)
        {
            for (int y = ly; y <= ry; ++y)
                if (ans < grid[x][y])
                {
                    ans = grid[x][y];
                    mx = x;
                    my = y;
                }
        }

        printf("%d %d %d\n", mx, my, ans);
        for (int i = lx; i <= rx; ++i)
            memset(grid[i], 0, sizeof grid[i]);
    }

    return 0;
}