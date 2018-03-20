#include <cstdio>
#include <cstring>
#include <queue>
#define N 10001

struct node
{
    int v, next;
};
inline int read()
{
    int n = 0;
    char ch;
    while ((ch = getchar()) >= '0' && ch <= '9')
        n = n * 10 + ch - '0';

    return n;
}
int main()
{
    //freopen("test.out", "w", stdout);
    
    int adj[N];//adjacent list
    node edge[N];
    bool visited[N];

    int T;
    scanf("%d ", &T);
    while (T--)
    {
        int n = read(), m = read(), l = read();
        //scanf("%d%d%d ", &n, &m, &l);

        memset(visited, false, sizeof visited);
        memset(adj, -1, sizeof adj);
        int idx = 0;

        int u, v;
        for (int i = 0; i < m; ++i)
        {
            //scanf("%d%d", &u, &v);
            u = read();
            v = read();
            edge[idx] = (node){v, adj[u]};
            adj[u] = idx++;
        }

        std::queue<int> Q;
        for (int i = 0; i < l; ++i)
        {
            //scanf("%d", &u);
            u = read();
            if (!visited[u]) //防止推一樣的
            {
                visited[u] = true;
                Q.push(u);
            }
        }

        int ans = 0;
        while (!Q.empty())
        {
            ++ans;
            int now = Q.front();
            Q.pop();

            for (int i = adj[now]; i != -1; i = edge[i].next)
            {
                int v = edge[i].v;
                if (!visited[v])
                {
                    visited[v] = true;
                    Q.push(v);
                }
            }
        }

        printf("%d\n", ans);
    }

    return 0;
}