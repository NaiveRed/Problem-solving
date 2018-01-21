#include <cstdio>
#include <cstring>
#include <queue>
#define N 100
using namespace std;

bool d[N][N];
void bfs(int s, int n, int cost[])
{
    bool visit[N] = {};
    queue<int> q;
    q.push(s);
    cost[s] = 0;
    visit[s] = true;

    while (!q.empty())
    {
        int now = q.front();
        q.pop();

        for (int i = 0; i < n; i++)
            if (!visit[i] && d[now][i])
            {
                cost[i] = cost[now] + 1;
                visit[i] = true;
                q.push(i);
            }
    }
}
int main()
{
    //freopen("test.out", "w", stdout);
    int T;

    scanf("%d", &T);
    for (int t = 1; t <= T; t++)
    {
        int n, r, i, j, k;
        scanf("%d", &n);

        memset(d, false, sizeof d);

        scanf("%d", &r);
        while (r--)
        {
            int u, v;
            scanf("%d%d", &u, &v);
            d[u][v] = d[v][u] = true;
        }

        int from_s[N] = {}, to_goal[N] = {};
        int s, goal, ans = 0;

        scanf("%d%d", &s, &goal);
        
        //bfs 以求出最短
        bfs(s, n, from_s);     //計算起點到各點的時間
        bfs(goal, n, to_goal); //計算各點到終點的時間

        //最久的
        for (i = 0; i < n; i++)
            if (ans < from_s[i] + to_goal[i])
                ans = from_s[i] + to_goal[i];

        printf("Case %d: %d\n", t, ans);
    }
    return 0;
}