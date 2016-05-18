#include<cstdio>
#include<algorithm>
#include<utility>
#include<cmath>
#define N 500
using namespace std;
typedef pair<int, int> Coord;

struct Edge
{
    int a, b;//idx of coord[]
    double dis;
    bool operator<(const Edge& e){ return dis < e.dis; }

}edge[126000];
int p[N];
inline void init(int n);
inline int find(int a);
inline void Union(int a, int b);
inline double getDistance(Coord& a, Coord& b);
double kruskal(int V, int E, int S);
int main()
{
    Coord coord[N];
    int Case;
    scanf("%d", &Case);
    while (Case--)
    {
        int S, P, i;
        scanf("%d%d", &S, &P);
        for (i = 0; i < P; i++)
            scanf("%d%d", &coord[i].first, &coord[i].second);

        int e = 0;
        for (i = 0; i < P; i++)
            for (int j = i + 1; j < P; j++)
            {
            edge[e].a = i;
            edge[e].b = j;
            edge[e++].dis = getDistance(coord[i], coord[j]);
            }

        printf("%.2lf\n", kruskal(P, e, S));
    }

    return 0;
}
double getDistance(Coord& a, Coord& b)
{
    return sqrt((a.first - b.first)*(a.first - b.first) + (a.second - b.second)*(a.second - b.second));
}

void init(int n)
{
    for (int i = 0; i < n; i++)
        p[i] = i;
}
int find(int a)
{
    return a == p[a] ? a : (p[a] = find(p[a]));
}
void Union(int a, int b)
{
    p[find(a)] = find(b);
}
double kruskal(int V, int E, int S)
{
    init(V);
    sort(edge, edge + E);
    double D = 0;

    //s 個衛星可省去 s-1 個邊
    for (int i = 1, e = 0; i < V - (S - 1) && e < E; i++)
    {
        while (find(edge[e].a) == find(edge[e].b))
            e++;

        Union(edge[e].a, edge[e].b);

        D = edge[e].dis;

        e++;
    }

    return D;
}