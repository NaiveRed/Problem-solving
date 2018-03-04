#include <cstdio>
#include <cstring>
#include <queue>
#include <utility>
#define N 85
using namespace std;

int main()
{
    //freopen("test.out", "w", stdout);
    const int dir[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    int T;
    char grid[31][N];

    scanf("%d ", &T);
    while (T--)
    {
        int r = 0, c, s_r, s_c;
        while (fgets(grid[r], N, stdin) && grid[r][0] != '_')
        {
            for (c = 0; grid[r][c] != '\n'; ++c)
                if (grid[r][c] == '*')
                {
                    s_r = r;
                    s_c = c;
                }

            grid[r++][c] = '\0';
        }

        grid[r][strlen(grid[r]) - 1] = '\0';

        //BFS
        queue<pair<int, int>> Q;
        Q.emplace(s_r, s_c);
        grid[s_r][s_c] = '#';
        while (!Q.empty())
        {
            int now_r = Q.front().first, now_c = Q.front().second;
            Q.pop();
            for (int i = 0; i < 4; ++i)
            {
                int rr = now_r + dir[i][0], cc = now_c + dir[i][1];
                if (grid[rr][cc] == ' ')
                {
                    grid[rr][cc] = '#';
                    Q.emplace(rr, cc);
                }
            }
        }

        for (int i = 0; i <= r; ++i)
            puts(grid[i]);
    }

    return 0;
}