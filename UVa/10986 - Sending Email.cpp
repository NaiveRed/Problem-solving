#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>
#define N 20000
using namespace std;

struct Node
{
    int v, w;
    Node(){}
    Node(int vv, int ww) :v(vv), w(ww){}
    bool operator<(const Node& a)const{return w > a.w; }//¤pªºÀu¥ý
};
vector<Node>list[N];//adjacent list
int dijkstra(int s, int goal, int n);
int main()
{
    int Case;
    scanf("%d", &Case);
    for (int c = 1; c <= Case; c++)
    {
        int n, m, s, t, u, v, w, i;
        scanf("%d%d%d%d", &n, &m, &s, &t);
        for (i = 0; i < n; i++)
            list[i].clear();

        for (int i = 0; i < m; i++)
        {
            scanf("%d%d%d", &u, &v, &w);
            list[u].push_back(Node(v, w));
            list[v].push_back(Node(u, w));
        }

        printf("Case #%d: ", c);
        int ans = dijkstra(s, t, n);
        if (ans == 1e9)
            puts("unreachable");
        else
            printf("%d\n", ans);
    }

    return 0;
}
int dijkstra(int s, int goal, int n)
{
    bool isVisit[N] = {};
    int d[N];
    fill(d, d + n, 1e9);

    d[s] = 0;
    priority_queue<Node> PQ;
    PQ.push(Node(s, 0));

    while (true)
    {
        int next = -1;
        while (!PQ.empty() && isVisit[next = PQ.top().v])
            PQ.pop();

        if (next == -1 || next == goal)
            return d[goal];
        isVisit[next] = true;

        for (Node node : list[next])
        {
            if (!isVisit[node.v] && d[next] + node.w < d[node.v])
            {
                d[node.v] = d[next] + node.w;
                PQ.push(Node(node.v, d[node.v]));
            }
        }
    }

    return d[goal];
}