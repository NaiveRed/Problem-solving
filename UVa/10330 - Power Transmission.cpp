//Zerojudge 上要使用 scanf
#include <cstdio>
#include <cstring>
#include <queue>
#define N 205
#define MIN(a, b) ((a) > (b) ? (b) : (a))
#define IN(x) ((x) << 1)
#define OUT(x) (IN(x) + 1)
using namespace std;

int n;
int adj[N][N];
int d[N];
bool visited[N];
inline int read()
{
    int n = 0;
    char ch;
    while ((ch = getchar()) >= '0' && ch <= '9')
        n = n * 10 + ch - '0';

    return n;
}
void BFS()
{
    memset(d, 0, sizeof d);
    queue<int> Q;
    Q.push(0);
    d[0] = 1; //B
    while (!Q.empty())
    {
        int now = Q.front();
        Q.pop();
        for (int i = 1; i <= OUT(n); ++i)
        {
            if (adj[now][i] > 0 && !d[i])
            {
                d[i] = d[now] + 1;

                if (i == 1) //D
                    return;

                Q.push(i);
            }
        }
    }
}
int DFS(int from, int df)
{
    if (from == 1)
        return df;

    for (int i = 1; i <= OUT(n); ++i)
    {
        if (adj[from][i] > 0 && !visited[i] && d[from] + 1 == d[i])
        {
            int f = DFS(i, MIN(df, adj[from][i]));
            visited[i] = true;
            if (f != 0)
            {
                adj[from][i] -= f;
                adj[i][from] += f;
                return f;
            }
        }
    }

    return 0;
}
int main()
{
    //freopen("test.out", "w", stdout);
    int m;
    while (scanf("%d", &n) != EOF)
    {
        getchar();
        //0: B, 1: D
        int u, v, c;
        for (int i = 1; i <= n; ++i)
        {
            //scanf("%d", &c);
            c = read();
            adj[OUT(i)][IN(i)] = adj[IN(i)][OUT(i)] = c;
        }

        scanf("%d ", &m);
        for (int i = 0; i < m; ++i)
        {
            u = read();
            v = read();
            c = read();
            //scanf("%d%d%d", &u, &v, &c);
            adj[OUT(u)][IN(v)] += c;
        }

        int B, D;
        scanf("%d%d ", &B, &D);
        for (int i = 0; i < B; ++i)
        {
            //scanf("%d", &u);
            u = read();
            adj[0][IN(u)] = 1e9;
        }
        for (int i = 0; i < D; ++i)
        {
            //scanf("%d", &u);
            u = read();
            adj[OUT(u)][1] = 1e9;
        }

        //Dinic Algo.
        int flow = 0;
        while (true)
        {
            BFS();
            if (!d[1])
                break;
            int f = 0;
            while (true)
            {
                memset(visited, false, sizeof visited);
                if ((f = DFS(0, 1e9)) != 0)
                    flow += f;
                else
                    break;
            }
        }

        printf("%d\n", flow);

        //init
        for (int i = 0; i <= OUT(n); ++i)
            memset(adj[i], 0, sizeof adj[i]);
    }

    return 0;
}