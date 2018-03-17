#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
#define N 102
#define IN(x) ((x - 1) << 1)
#define OUT(x) (IN(x) + 1)
using namespace std;

int M, W;
int adj[N][N]; //residue capacity
int parent[N];
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
    memset(parent, 0, sizeof parent);

    queue<int> Q;
    Q.push(s);
    parent[s] = s;
    while (!Q.empty() && !parent[t])
    {
        int now = Q.front();
        Q.pop();

        for (int i = 1; i <= OUT(M); ++i)        
        {            
            if (adj[now][i] > 0 && !parent[i])
            {
                Q.push(i);
                parent[i] = now;
                if (i == t)
                    break;
            }
        }
    }
}
int main()
{
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

        //Edmonds-Karp Algo.
        int flow = 0;
        while (true)
        {
            int s = OUT(1), t = IN(M);
            BFS(s, t);

            if (!parent[t])
                break;
            /*for(int from = parent[t],to = t; from!=to; from = parent[to = from])
                printf("%d -> %d\n",from,to);*/
            int new_f = 1e9;
            for (int from = parent[t], to = t; from != to; from = parent[to = from])
                new_f = min(adj[from][to], new_f);
            for (int from = parent[t], to = t; from != to; from = parent[to = from])
            {
                adj[from][to] -= new_f;
                adj[to][from] += new_f;
            }

            flow += new_f;
        }

        printf("%d\n", flow);

        //init
        for (int i = 0; i <= OUT(M); ++i)
            memset(adj[i], 0, sizeof adj[i]);
    }

    return 0;
}
