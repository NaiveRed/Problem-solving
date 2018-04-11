#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 500001
typedef long long LL;
using namespace std;

struct edge
{
    int v, t, next; // t 為單趟時間，來回時間要乘 2
} E[100000];
int adj[N];
bool visited[N];
LL V[N]; //需要拜訪的次數
LL DP[N], min_time, sum;
int ans[N], ans_idx;
inline int read()
{
    int n = 0;
    char c;
    while ((c = getchar()) >= '0' && c <= '9')
        n = n * 10 + c - '0';
    return n;
}
/*
DFS1:
1. 計算以 1 為根需要經過各個點幾次
2. 計算 DP[1] 為待會狀態轉移的初始狀態
*/
void DFS1(int a, int cnt_time)
{
    for (int i = adj[a]; i != -1; i = E[i].next)
    {
        int b = E[i].v, t = cnt_time + E[i].t;

        if (!visited[b])
        {
            visited[b] = true;
            DP[1] += (LL)V[b] * t * 2;

            DFS1(b, t);

            V[a] += V[b];
        }
    }
}
//DFS2: DP on tree
void DFS2(int a)
{
    for (int i = adj[a]; i != -1; i = E[i].next)
    {
        int b = E[i].v;

        if (!visited[b])
        {
            visited[b] = true;
            
            /*
            DP[b] = DP[a] - (V[b] * E[i].t << 1) + (sum - V[b]) * (E[i].t << 1);
            (V[b] * E[i].t << 1): 該點(b)下方少走的
            (sum - V[b]) * (E[i].t << 1): 該點(b)上方要多走的路
            */
            DP[b] = DP[a] + (sum - (V[b] << 1)) * (E[i].t << 1);
            if (DP[b] < min_time)
            {
                min_time = DP[b];
                ans[0] = b;
                ans_idx = 1;
            }
            else if (DP[b] == min_time)
                ans[ans_idx++] = b;

            DFS2(b);
        }
    }
}
int main()
{
    //freopen("test.in", "r", stdin);
    //freopen("test.out", "w", stdout);
    int C;
    scanf("%d ", &C);
    while (C--)
    {
        memset(adj, -1, sizeof adj);

        int n, a, b, t, idx = 0;
        //scanf("%d ", &n);
        n = read();
        for (int i = 0; i < n - 1; ++i)
        {
            //scanf("%d%d%d", &a, &b, &t);
            a = read();
            b = read();
            t = read();
            E[idx] = (edge){b, t, adj[a]}; //a -> b
            adj[a] = idx++;
            E[idx] = (edge){a, t, adj[b]}; //b -> a
            adj[b] = idx++;
        }

        int m, f;
        //scanf("%d ", &m);
        m = read();
        for (int i = 0; i < m; ++i)
        {
            //scanf("%d%d", &a, &f);
            a = read();
            f = read();
            V[a] = f;
            sum += f;
        }

        visited[1] = true;

        DFS1(1, 0);

        min_time = DP[1];
        ans[0] = 1;
        ans_idx = 1;

        memset(visited, false, sizeof visited);
        visited[1] = true;
        DFS2(1);

        sort(ans, ans + ans_idx);
        printf("%lld\n", min_time);
        printf("%d", ans[0]);
        for (int i = 1; i < ans_idx; ++i)
            printf(" %d", ans[i]);
        putchar('\n');

        //init
        sum = 0;
        memset(visited, false, sizeof visited);
        memset(V, 0, sizeof V);
        memset(DP, 0, sizeof DP);
    }

    return 0;
}