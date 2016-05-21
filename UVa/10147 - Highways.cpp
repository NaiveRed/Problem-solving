#include<cstdio>
#include<utility>
#include<cmath>
#include<vector>
#include<queue>
#include<functional>
#define N 750
using namespace std;
typedef pair<int, int> Coord;

struct Node
{
    int a;//idx of coord[]
    double dis;
    Node(){}
    Node(int aa, double d) :a(aa), dis(d){}
    bool operator >(const Node& n)const{ return dis > n.dis; };
};

vector<Node> adjList[N];
double getDistance(Coord& a, Coord& b);
void prim(int n);
int main()
{
    Coord coord[N];
    int Case;
    scanf("%d", &Case);
    while (Case--)
    {
        int n, m, i;
        scanf("%d", &n);
        for (i = 0; i < n; i++)
            adjList[i].clear();
        for (i = 0; i < n; i++)
            scanf("%d%d", &coord[i].first, &coord[i].second);

        //建邊
        for (i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
            {
            double dis = getDistance(coord[i], coord[j]);
            adjList[i].push_back(Node(j, dis));
            adjList[j].push_back(Node(i, dis));
            }

        int a, b;
        scanf("%d", &m);
        //已經建好的邊，權重設為 0
        for (i = 0; i < m; i++)
        {
            scanf("%d%d", &a, &b);
            adjList[a - 1].push_back(Node(b - 1, 0));
            adjList[b - 1].push_back(Node(a - 1, 0));
        }

        prim(n);

        if (Case)
            putchar('\n');
    }

    return 0;
}
double getDistance(Coord& a, Coord& b)
{
    return sqrt((a.first - b.first)*(a.first - b.first) + (a.second - b.second)*(a.second - b.second));
}
void prim(int n)
{
    int parent[N] = {}, i;
    double d[N] = {};
    bool isVisit[N] = {}, flag = true;
    for (i = 0; i < n; i++)
        d[i] = 1e9;
    priority_queue<Node, vector<Node>, greater<Node> > PQ;
    PQ.push(Node(0, 0));
    d[0] = 0;

    for (i = 0; i < n; i++)
    {
        Node next;
        while (isVisit[(next = PQ.top()).a])
            PQ.pop();

        //新建的路
        if (next.dis)
        {
            printf("%d %d\n", parent[next.a] + 1, next.a + 1);
            flag = false;
        }

        isVisit[next.a] = true;
        int size = adjList[next.a].size();
        for (int k = 0; k < size; k++)
        {
            Node node = adjList[next.a][k];
            if (!isVisit[node.a] && node.dis < d[node.a])
            {
                d[node.a] = node.dis;
                parent[node.a] = next.a;
                PQ.push(node);
            }
        }
    }

    if (flag)
        puts("No new highways need");
}