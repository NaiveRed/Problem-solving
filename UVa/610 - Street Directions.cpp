/*
本來的路都是雙向，跟無向圖情況相同，若有 back edge，
該段就不會是 bridge，拿掉那段，中間兩點仍可來回無礙(走 back edge)。
但今天是有向圖，就算有 back edge 仍需維持該段的其中一向，才能透過 back edge 來回互通。
若無 back edge 該段就必須是雙向的路。
*/
#include <cstdio>
#include <cstring>
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define M 4000
#define N 1001

struct edge
{
    int v, next;
} E[M];
int adj[N];
int low[N], visited[N];
int step;
inline int read()
{
    int n = 0;
    char c;
    while ((c = getchar()) >= '0' && c <= '9')
        n = n * 10 + c - '0';
    return n;
}
void DFS(int p, int u) //p -> u
{
    visited[u] = low[u] = ++step;

    for (int i = adj[u]; i != -1; i = E[i].next)
    {
        //u -> v
        int v = E[i].v;
        if (!visited[v])
        {
            //tree edge
            printf("%d %d\n", u, v);
            DFS(u, v);
            low[u] = MIN(low[u], low[v]);
            if (low[v] > visited[u]) //bridge
                printf("%d %d\n", v, u);
        }
        else if (v != p) //back edge
        {
            //往上走 back edge，而不是往下走已經探查過的點
            //因為兩者都是 visited[i] != 0，所以要再判斷
            if (visited[v] < visited[u])
                printf("%d %d\n", u, v);

            low[u] = MIN(visited[v], low[u]);
        }
    }
}
int main()
{
    //freopen("test.out", "w", stdout);
    int n, m, Case = 0;
    while (scanf("%d%d ", &n, &m) && (n || m))
    {
        int u, v, idx = 0;
        memset(adj, -1, sizeof adj);
        for (int i = 0; i < m; ++i)
        {
            u = read();
            v = read();
            //scanf("%d%d", &u, &v);
            E[i << 1] = (edge){v, adj[u]}; //u -> v
            adj[u] = idx++;
            E[(i << 1) + 1] = (edge){u, adj[v]}; //v -> u
            adj[v] = idx++;
        }

        printf("%d\n\n", ++Case);

        for (int i = 1; i <= n; ++i)
            if (!visited[i])
                DFS(-1, i);
        puts("#");

        //init
        memset(visited, 0, sizeof visited);
        memset(low, 0, sizeof low);
        step = 0;
    }

    return 0;
}