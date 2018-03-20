#include <cstdio>
#include <cstring>
#define N 10001
#define S 30000

struct node
{
    int v, next;
};
node edge[S];
int n, imp_size; //總車站數, 重點車站的數量
int adj[N];      //adjacent list
int used[N];     //計算重點車站
char str[10000];
inline int read()
{
    int n = 0;
    char ch;
    while ((ch = getchar()) >= '0' && ch <= '9')
        n = n * 10 + ch - '0';

    return n;
}
int BFS(int start)
{
    static int Q[N]; //queue
    int visited[N] = {};

    Q[0] = start;
    int qf = 0, qb = 1; //queue
    int times = 0;      //耗時，兩小時為一單位
    int count = 1;      //已到達的車站數
    visited[start] = 1; //方便判斷，每個都多 1

    while (qf < qb)
    {
        int now = Q[qf++];

        for (int i = adj[now]; i != -1; i = edge[i].next)
        {
            int v = edge[i].v;
            if (!visited[v])
            {
                visited[v] = visited[now] + 1;

                if (used[v] > 1) //important
                {
                    times += visited[v];
                    if (++count == imp_size)
                        return times;
                }

                Q[qb++] = v;
            }
        }
    }

    return 1e9;
}
int main()
{
    int T = read();    
    
    while (T--)
    {
        memset(adj, -1, sizeof adj);
        int imp[100]; // 重點車站
        int s, idx = 0;
        imp_size = 0;
        n = read();
        s = read();

        for (int i = 0; i < s; ++i)
        {
            int u = read(), v;
            ++used[u];
            while ((v = read()) != 0)
            {
                edge[idx] = (node){v, adj[u]}; //u -> v
                adj[u] = idx++;
                edge[idx] = (node){u, adj[v]}; //v -> u
                adj[v] = idx++;

                if (used[u = v] < 2)
                    ++used[u];
            }
        }

        for (int i = 1; i <= n; ++i)
            if (used[i] > 1)
                imp[imp_size++] = i;

        int min_time = 1e9, ans = 0;
        for (int i = 0; i < imp_size; ++i)
        {
            int sum = BFS(imp[i]);
            if (sum < min_time)
            {
                min_time = sum;
                ans = imp[i];
            }
            else if (sum == min_time && imp[i] < ans)
                ans = imp[i];
        }

        printf("Krochanska is in: %d\n", ans);
        memset(used, 0, sizeof used);
    }

    return 0;
}