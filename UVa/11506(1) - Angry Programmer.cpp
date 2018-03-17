#include <cstdio>
#include <cstring>
#include <queue>
#include <stack>
#include <algorithm>
#define N 102
#define IN(x) ((x - 1) << 1)
#define OUT(x) (IN(x) + 1)
using namespace std;

int M, W;
int adj[N][N]; //residue capacity, adjacent matrix
int d[N];
int visited[N];
int parent[N]; //for dfs(stack)
inline int input()
{
    int n = 0;
    char c;
    while ((c = getchar()) <= '9' && c >= '0')
        n = n * 10 + c - '0';
    return n;
}

void BFS(int s, int t)
{
    fill(d, d + N, 1e9);
    memset(visited, false, sizeof visited);

    queue<int> Q;
    Q.push(s);
    d[s] = 0;
    visited[s] = true;
    while (!Q.empty())
    {
        int now = Q.front();
        Q.pop();

        for (int i = 1; i <= OUT(M); ++i)
        {
            if (adj[now][i] > 0 && !visited[i])
            {
                visited[i] = true;
                d[i] = d[now] + 1;
                Q.push(i);

                if (i == t)
                    return;
            }
        }
    }
}

//recursive verion
int DFS(int from, int t, int df)
{
    if (from == t)
        return df;

    for (int i = 1; i <= OUT(M); ++i)
    {
        if (adj[from][i] > 0 && d[from] + 1 == d[i] && !visited[i])
        {
            int f;
            visited[i] = true;

            if ((f = DFS(i, t, min(df, adj[from][i]))) != 0)
            {
                adj[from][i] -= f;
                adj[i][from] += f;
                return f;
            }
        }
    }

    return 0;
}

//stack version
/*int DFS(int s, int t)
{
    memset(parent, -1, sizeof parent);
    int df = 1e9;
    stack<int> stk;
    parent[s] = s;
    stk.push(s);

    while (!stk.empty())
    {
        int now = stk.top();
        stk.pop();

        for (int i = 1; i <= OUT(M); ++i)
        {
            if (adj[now][i] > 0 && d[now] + 1 == d[i] && parent[i] == -1)
            {
                df = min(df, adj[now][i]);
                parent[i] = now;
                stk.push(i);

                if (t == i)
                {
                    for (int from = parent[t], to = t; from != to; from = parent[to = from])
                    {
                        adj[from][to] -= df;
                        adj[to][from] += df;
                    }
                    return df;
                }
            }
        }
    }

    return 0;
}*/
int main()
{
    //freopen("test.out", "w", stdout);
    while (scanf("%d%d ", &M, &W) && (M || W))
    {
        adj[IN(1)][OUT(1)] = adj[OUT(1)][IN(1)] = 1e9; //s, boss
        adj[IN(M)][OUT(M)] = adj[OUT(M)][IN(M)] = 1e9; //t, central

        int m1, m2, c;
        for (int i = 0; i < M - 2; ++i)
        {
            //scanf("%d%d",&m1,&c);
            m1 = input();
            c = input();
            adj[IN(m1)][OUT(m1)] = adj[OUT(m1)][IN(m1)] = c;
        }

        for (int i = 0; i < W; ++i)
        {
            //scanf("%d%d%d",&m1,&m2,&c);
            m1 = input();
            m2 = input();
            c = input();
            //m2_out -> m1_in, m1_out -> m2_in
            adj[OUT(m2)][IN(m1)] = adj[OUT(m1)][IN(m2)] = c;
        }

        //Dinic Algo.
        int flow = 0;
        while (true)
        {
            int s = OUT(1), t = IN(M);
            BFS(s, t);

            if (d[t] == 1e9)
                break;
            int f = 0;
            while (true)
            {
                memset(visited, false, sizeof visited);
                if ((f = DFS(s, t, 1e9)) != 0)
                //if ((f = DFS(s, t)) != 0)
                    flow += f;
                else
                    break;
            }
        }

        printf("%d\n", flow);

        //init
        for (int i = 0; i <= OUT(M); ++i)
            memset(adj[i], 0, sizeof adj[i]);
    }

    return 0;
}