#include<cstdio>
#include<queue>
#include<vector>
#define N 1001
using namespace std;

struct Node
{
    int v, w;
    Node(){}
    Node(int vv, int ww) :v(vv), w(ww){}
    bool operator<(const Node& a) const
    {
        return w < a.w;
    }
};
vector<Node> adjList[N];
int prim(int n);
int main()
{
    int Case;
    scanf("%d", &Case);
    while (Case--)
    {
        int n, m, i, u, v, w;
        scanf("%d%d", &n, &m);
        for (i = 0; i < n; i++)
            adjList[i].clear();

        for (i = 0; i < m; i++)
        {
            scanf("%d%d%d", &u, &v, &w);
            adjList[u].push_back(Node(v, w));
            adjList[v].push_back(Node(u, w));
        }

        printf("%d\n", prim(n));
    }

    return 0;
}
int prim(int n)
{
    bool isVisit[N] = { };
    int d[N] = {}, sum = 0;
    d[0] = 0;
    priority_queue<Node> PQ;
    PQ.push(Node(0, 0));

    for (int i = 0; i < n; i++)//�Ĥ@�I + (n-1 ����) = n ��
    {
        Node next;
        while (isVisit[(next = PQ.top()).v])
            PQ.pop();
        PQ.pop();
        sum += next.w;
        isVisit[next.v] = true;

        int len = adjList[next.v].size();
        for (int j = 0; j < len; j++)
        {
            Node node = adjList[next.v][j];
            if (!isVisit[node.v] && d[node.v] < node.w)
            {
                d[node.v] = node.w;
                PQ.push(node);
            }
        }
    }

    return sum;
}