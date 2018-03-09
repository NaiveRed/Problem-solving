#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <utility>
#include <queue>
#include <vector>
#include <algorithm>
#define N 1000
using namespace std;
typedef pair<int, int> pos;
typedef pair<pos, int> node;

const int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
bool bomb[N][N];
int dis[N][N];
int R, C;
inline bool in_bound(pos &p)
{
    return p.first >= 0 && p.second >= 0 && p.first < R && p.second < C;
}
inline int heuristic(pos &a, pos &b)
{
    //Manhattan distance
    return abs(a.first - b.first) + abs(a.second - b.second);
}
int a_star(pos &src, pos &des)
{
    priority_queue<node, vector<node>, bool (*)(const node &, const node &)> PQ([](const node &a, const node &b) -> bool {
        return a.second > b.second;
    });

    PQ.emplace(src, 0);
    bomb[src.first][src.second] = true;

    for (int i = 0; i < R; ++i)
        fill(dis[i], dis[i] + C, 1e9);
    dis[src.first][src.second] = 0;

    while (true)
    {
        pos now = PQ.top().first;
        PQ.pop();

        if (now == des)
            return dis[des.first][des.second];

        bomb[now.first][now.second] = true;

        for (int i = 0; i < 4; ++i)
        {
            pos next(now.first + dir[i][0], now.second + dir[i][1]);
            if (in_bound(next) && !bomb[next.first][next.second])
            {
                if (dis[next.first][next.second] > dis[now.first][now.second] + 1)
                {
                    dis[next.first][next.second] = dis[now.first][now.second] + 1;
                    PQ.emplace(next, heuristic(next, des) + dis[next.first][next.second]);
                }
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
        for (int i = 0; i < n; ++i)
        {
            scanf("%d%d", &r, &x);
            for (int j = 0; j < x; ++j)
            {
                scanf("%d", &c);
                bomb[r][c] = true;
            }
        }

        pos src, des;
        scanf("%d%d%d%d", &src.first, &src.second, &des.first, &des.second);

        printf("%d\n", a_star(src, des));

        //init
        for (int i = 0; i < R; ++i)
            memset(bomb[i], false, sizeof bomb[i]);
    }

    return 0;
}