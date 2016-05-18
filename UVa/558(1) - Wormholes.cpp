#include<cstdio>
#include<algorithm>
#include<queue>
#include<vector>
#define N 1000
#define MAX 100000000
using namespace std;

struct Node{

    int b, t;
    Node(){}
    Node(int v, int w) : b(v), t(w){}
};
vector<Node> edge[N];
bool SPFA(int n);
int main()
{
    int Case, n, m;
    scanf("%d", &Case);
    while (Case--)
    {
        int a, b, t, i;
        scanf("%d%d", &n, &m);
        for (i = 0; i < n; i++)
            edge[i].clear();
        for (i = 0; i < m; i++)
        {
            scanf("%d%d%d", &a, &b, &t);
            edge[a].push_back(Node(b, t));
        }

        puts(SPFA(n) ? "possible" : "not possible");
    }

    return 0;
}
bool SPFA(int n)
{
    bool in[N] = {};
    int d[N];
    fill(d, d + n, MAX);
    d[0] = 0;

    int r[N] = {};//最短路徑的邊數
    queue<int> Q;
    Q.push(0);

    while (!Q.empty())
    {
        int next = Q.front();
        Q.pop();

        in[next] = false;
        for (Node node : edge[next])
        {
            if (d[next] + node.t < d[node.b])
            {
                d[node.b] = d[next] + node.t;
                r[node.b] = r[next] + 1;
                if (r[node.b] > n - 1)
                    return true;
                if (!in[node.b])
                {
                    Q.push(node.b);
                    in[node.b] = true;
                }
            }
        }

    }

    return false;
}