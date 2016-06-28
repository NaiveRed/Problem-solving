#include<cstdio>
#include<queue>
#include<stack>
#define N 11
using namespace std;

struct Node{
    int u, d;
    Node(int uu, int dd) :u(uu), d(dd){}
    bool operator<(const Node& n)const{ return d>n.d; }
};
int adjM[N][N];

void dijkstra(int s, int g);
int main()
{
    int n, i, j, Case = 1;
    while (scanf("%d", &n) && n)
    {
        for (i = 0; i < N; i++)
            for (j = 0; j < N; j++)
                adjM[i][j] = -1;

        int t, u, d;
        for (i = 1; i <= n; i++)
        {
            scanf("%d", &t);
            for (j = 0; j < t; j++)
            {
                scanf("%d%d", &u, &d);
                adjM[i][u] = d;
            }
        }
        int s, g;
        scanf("%d%d", &s, &g);
        printf("Case %d: Path =", Case++);
        dijkstra(s, g);
    }

    return 0;
}
void dijkstra(int s, int g)
{
    int d[N] = {}, path[N] = {};
    bool isVisit[N] = {};
    priority_queue<Node> PQ;
    PQ.push(Node(s, 0));

    for (int i = 0; i < N; i++)
        d[i] = 1e9;

    d[s] = 0;
    while (true)
    {
        int next = -1;
        while (!PQ.empty() && isVisit[next = PQ.top().u])
            PQ.pop();

        if (next == -1 || next == g)
            break;

        PQ.pop();
        isVisit[next] = true;

        for (int i = 1; i < N; i++)
            if (!isVisit[i] && adjM[next][i] != -1)
                if (d[next] + adjM[next][i] < d[i])
                {
            d[i] = d[next] + adjM[next][i];
            path[i] = next;
            PQ.push(Node(i, d[i]));
                }
    }

    int last = g;
    stack<int> Stack;
    Stack.push(g);
    while (last != s)
    {
        last = path[last];
        Stack.push(last);
    }

    while (!Stack.empty())
    {
        printf(" %d", Stack.top());
        Stack.pop();
    }

    printf("; %d second delay\n", d[g]);
}