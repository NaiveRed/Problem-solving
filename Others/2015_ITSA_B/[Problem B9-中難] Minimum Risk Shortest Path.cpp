#include<cstdio>
#include<vector>
#include<queue>
#include<functional>
#define MAX(a,b) ((a)>(b)?(a):(b))
#define N 500
using namespace std;

struct Node
{
    int v, risk, w;
    Node(){}
    Node(int vv, int r) :v(vv), risk(r){}
    Node(int vv, int r, int ww) :v(vv), risk(r), w(ww){}
    bool operator>(const Node& a)const{ return risk > a.risk; }//std::greater,用來找到終點所需的最小風險
    bool operator<(const Node& a)const{ return w>a.w; }//std::less,用來找到終點所需的最短路徑
};
vector<Node> adjList[N];

int getMinRisk(int n);
int dijkstra(int n, int min);
int main()
{
    int Case;
    scanf("%d", &Case);
    while (Case--)
    {
        int n, m, i, u, v, r, w;
        scanf("%d%d", &n, &m);
        for (i = 0; i < n; ++i)
            adjList[i].clear();

        for (i = 0; i < m; ++i)
        {
            scanf("%d%d%d%d", &u, &v, &r, &w);
            adjList[u].push_back(Node(v, r, w));
        }
        int min;
        if ((min = getMinRisk(n)) == -1)
            puts("-1");
        else
            printf("%d %d\n", min, dijkstra(n, min));
    }

    return 0;
}
int getMinRisk(int n)
{
    bool isVisit[N] = {};
    int r[N] = {}, i;
    for (i = 1; i < n; i++)
        r[i] = 100000;

    priority_queue<Node, vector<Node>, greater<Node> > Q;
    Q.push(Node(0, 0));
    while (!Q.empty())
    {
        Node next = Q.top();
        Q.pop();
        isVisit[next.v] = true;

        if (next.v == n - 1)
            return next.risk;
        int len = adjList[next.v].size();
        for (i = 0; i < len; ++i)
        {
            Node node = adjList[next.v][i];
            int max = MAX(r[next.v], node.risk);
            if (!isVisit[node.v] && max < r[node.v])
            {
                r[node.v] = max;
                Q.push(Node(node.v, max));
            }

        }
    }

    return -1;
}
int dijkstra(int n, int min)
{
    bool isVisit[N] = {};
    int d[N] = {}, i;
    for (i = 1; i < n; i++)
        d[i] = 100000;

    priority_queue<Node, vector<Node>, less<Node> > Q;
    Q.push(Node(0, 0, 0));
    while (!Q.empty())
    {
        Node next = Q.top();
        Q.pop();
        isVisit[next.v] = true;

        if (next.v == n - 1)
            return next.w;

        int len = adjList[next.v].size();
        for (i = 0; i < len; ++i)
        {
            Node node = adjList[next.v][i];
            int dis = d[next.v] + node.w;
            if (!isVisit[node.v] && dis < d[node.v] && node.risk <= min)//風險不得超過最小風險
            {
                d[node.v] = dis;
                Q.push(Node(node.v, node.risk, dis));
            }
        }
    }

    return -1;
}