#include <cstdio>
#include <cstring>
#include <utility>
#include <queue>
#define N 1000
using namespace std;
typedef pair<int, int> pos;

const int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int dis[N][N];
int R, C;
inline int input()
{
    int n = 0;
    char c;
    while ((c = getchar()) != '\n' && c != ' ')
        n = n * 10 + c - '0';
    return n;
}
inline bool in_bound(int r, int c)
{
    return r >= 0 && c >= 0 && r < R && c < C;
}
int BFS(pos &src, pos &des)
{
    queue<pos> Q;
    Q.push(src);
    dis[src.first][src.second] = 1;

    while (!Q.empty())
    {
        pos now = Q.front();
        Q.pop();

        for (int i = 0; i < 4; ++i)
        {
            int r = now.first + dir[i][0], c = now.second + dir[i][1];
            if (in_bound(r, c) && dis[r][c] == 0)
            {
                dis[r][c] = dis[now.first][now.second] + 1;

                pos next(r, c);
                if (next == des)
                    return dis[des.first][des.second] - 1;

                Q.push(next);
            }
        }
    }

    return -1;
}
int main()
{
    //freopen("test.out", "w", stdout);

    while (scanf("%d%d", &R, &C) && R)
    {
        int n, r, c, x;
        scanf("%d", &n);
        getchar();
        for (int i = 0; i < n; ++i)
        {
            r = input();
            x = input();
            //scanf("%d%d", &r, &x);
            for (int j = 0; j < x; ++j)
            {
                c = input();
                //scanf("%d", &c);
                dis[r][c] = -1;
            }
        }

        pos src, des;
        scanf("%d%d%d%d", &src.first, &src.second, &des.first, &des.second);

        printf("%d\n", BFS(src, des));

        //init
        for (int i = 0; i < R; ++i)
            memset(dis[i], 0, sizeof dis[i]);
    }

    return 0;
}