#include <cstdio>
#include <cstring>
#include <vector>
#include <utility>
#include <algorithm>
#define N 100
using namespace std;

vector<int> adj_list[N];
int visited[N], low[N];
int n, step;
vector<pair<int, int>> bridges;

void DFS(int p, int u) //p -> u
{
    visited[u] = low[u] = ++step;

    for (int v : adj_list[u])
        if (v != p)
        {
            if (visited[v]) //back edge
            {
                //走一次 back edge 能到的
                low[u] = min(low[u], visited[v]);
                //不斷走 tree edge 與 back edge
                //low[u] = min(low[u], low[v]);
            }
            else //tree edge
            {
                DFS(u, v);
                low[u] = min(low[u], low[v]);
                if (visited[u] < low[v]) //u -> v 為bridge
                    bridges.emplace_back(min(u, v), max(u, v));
            }
        }
}
int main()
{
    //freopen("test.out", "w", stdout);
    while (scanf("%d", &n) != EOF)
    {
        int i, j, u, v;
        for (i = 0; i < n; ++i)
        {
            scanf("%d (%d)", &u, &j);
            while (j--)
            {
                scanf("%d", &v);
                adj_list[u].push_back(v);
            }
        }

        //find bridges (cut-edge)
        for (i = 0; i < n; ++i)
            if (!visited[i])
                DFS(i, i);

        sort(bridges.begin(), bridges.end(),
             [](const pair<int, int> &a, const pair<int, int> &b) -> bool {
                 return a.first < b.first || (a.first == b.first && a.second < b.second);
             });

        printf("%d critical links\n", (int)bridges.size());
        for (auto p : bridges)
            printf("%d - %d\n", p.first, p.second);
        putchar('\n');

        //init
        for (i = 0; i < n; ++i)
            adj_list[i].clear();
        memset(visited, 0, sizeof visited);
        memset(low, 0, sizeof low);
        bridges.clear();
        step = 0;
    }

    return 0;
}