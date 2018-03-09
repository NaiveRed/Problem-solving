#include <cstdio>
#include <cstring>
#include <queue>
#define N 101
#define MIN(a, b) ((a) < (b) ? (a) : (b))

int main()
{
    //freopen("test.out", "w", stdout);
    int n, Case = 0;
    int adj[N][N] = {}; //residue capacity
    int path[N] = {};   //path[a] = b: b -> a

    while (scanf("%d", &n) && n) //1~n
    {
        int s, t, c, u, v, w;
        scanf("%d%d%d", &s, &t, &c);
        for (int i = 0; i < c; ++i)
        {
            scanf("%d%d%d", &u, &v, &w);
            adj[u][v] += w;
            adj[v][u] += w;
        }

        //Edmonds-Karp Algo.
        int flow = 0; //目前的流量

        while (true) //直到沒有擴充路徑(擴充流量)
        {
            //init
            memset(path, 0, sizeof path);

            std::queue<int> Q;
            //BFS 找擴充路徑
            Q.push(s);
            path[s] = s;
            while (!Q.empty() && !path[t])
            {
                int now = Q.front();
                Q.pop();
                for (int i = 1; i <= n; ++i)
                    if (!path[i] && adj[now][i] > 0)
                    {
                        path[i] = now;
                        Q.push(i);
                    }
            }

            if (!path[t]) //沒擴充路徑了
                break;

            // 更新擴充路徑上每一條邊的流量
            int new_f = 1e9;
            //先找出路徑上可容許的最小流量
            for (int from = path[t], to = t; from != to; from = path[to = from])
            {
                new_f = MIN(new_f, adj[from][to]);
                //to = from;
                //from = path[to];
            }
            //一條一條做填充
            for (int from = path[t], to = t; from != to; from = path[to = from])
            {
                adj[from][to] -= new_f;
                adj[to][from] += new_f;
            }
            flow += new_f;
        }

        printf("Network %d\nThe bandwidth is %d.\n\n", ++Case, flow);

        //init
        for (int i = 1; i <= n; ++i)
            memset(adj[i], 0, sizeof adj[i]);
    }

    return 0;
}