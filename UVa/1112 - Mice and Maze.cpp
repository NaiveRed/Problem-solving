#include <cstdio>
#include <vector>
#define N 101
#define INF 1e9
using namespace std;

struct Edge
{
    int to, d;
    Edge(int _to, int _d) : to(_to), d(_d) {}
};
int main()
{
    //freopen("test.in", "r", stdin);
    //freopen("test.out", "w", stdout);
    int Case;
    vector<Edge> edges[N];

    scanf("%d", &Case);
    while (Case--)
    {
        int n, goal, timer, m;
        scanf("%d%d%d%d", &n, &goal, &timer, &m);

        for (int i = 1; i <= n; i++)
            edges[i].clear();

        for (int i = 0; i < m; i++)
        {
            int u, v, d;
            scanf("%d%d%d", &u, &v, &d);
            //因為是單向, (u,v) 顛倒存, 方便求終點到各老鼠的時間
            edges[v].push_back(Edge(u, d));
        }

        //dijkstra
        int d[N] = {};
        bool visit[N] = {};
        for (int i = 0; i <= n; i++)
            d[i] = INF;
        d[goal] = 0;

        while (true)
        {
            int min = INF, now = 0;
            for (int i = 1; i <= n; i++)
                if (!visit[i] && min > d[i])
                {
                    min = d[i];
                    now = i;
                }

            if (!now)
                break;

            visit[now] = true;
            for (auto edge : edges[now])
                if (!visit[edge.to] && d[now] + edge.d < d[edge.to])
                    d[edge.to] = d[now] + edge.d;
        }

        int count = 0;
        for (int i = 1; i <= n; i++)
            if (d[i] <= timer)
                count++;

        printf("%d%s", count, Case ? "\n\n" : "\n");
    }

    return 0;
}