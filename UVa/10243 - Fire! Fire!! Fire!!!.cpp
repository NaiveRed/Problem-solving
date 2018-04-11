#include <cstdio>
#include <cstring>
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define N 1001
#define M 2000

struct edge
{
    int g, next;
} E[M];

int DP[N][2];
/*
DP[n][0]: 以 n 為根，且不在 n 設置出口時，所需要的出口數
DP[n][1]: 以 n 為根，且在 n 設置出口時，所需要的出口數
*/
int adj[N];//adjacent list
bool visited[N];
void DFS(int now)
{
    for (int i = adj[now]; i != -1; i = E[i].next)
    {
        int g = E[i].g;
        if (!visited[g])
        {
            visited[g] = true;
            DFS(g);
            DP[now][0] += DP[g][1];
            DP[now][1] += MIN(DP[g][0], DP[g][1]);
        }
    }
}
inline int read()
{
    int n = 0;
    char c;
    while ((c = getchar()) <= '9' && c >= '0')
        n = n * 10 + c - '0';
    return n;
}
int main()
{
    //freopen("test.out", "w", stdout);
    int n;
    while (scanf("%d ", &n) && n)
    {

        memset(adj, -1, sizeof adj);

        int k, g, idx = 0;
        for (int i = 1; i <= n; ++i)
        {
            DP[i][0] = 0; //不放
            DP[i][1] = 1; //放
            //scanf("%d", &k);
            k = read();
            for (int j = 0; j < k; ++j)
            {
                //scanf("%d", &g);
                g = read();
                E[idx] = (edge){g, adj[i]};
                adj[i] = idx++;
            }
        }

        if (n == 1)
        {
            puts("1");
            continue;
        }

        visited[1] = true;
        DFS(1);
        printf("%d\n", MIN(DP[1][0], DP[1][1]));

        memset(visited, false, N);
    }

    return 0;
}