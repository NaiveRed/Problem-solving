#include<cstdio>
#include<algorithm>
#define N 200001
using namespace std;

struct Road
{
    int u, v, w;
    bool operator<(const Road& a){ return w < a.w; }
}road[N];

int p[N];
inline void Union(int a, int b);
inline int find(int a);
int kruskal(int n, int e);
int main()
{
    int n, m;//junction,road

    while (scanf("%d%d", &n, &m) && n)
    {
        int cost = 0, i;

        for (i = 0; i < m; i++)
        {
            scanf("%d%d%d", &road[i].u, &road[i].v, &road[i].w);
            cost += road[i].w;
        }

        printf("%d\n", cost - kruskal(n, m));
    }

    return 0;
}
int kruskal(int n, int e)
{
    int i, now, cost = 0;
    //init
    for (i = 0; i < n; i++)
        p[i] = i;

    sort(road, road + e);

    for (i = 0, now = 0; i < e&&now < n - 1; i++, now++)
    {
        while (find(road[i].u) == find(road[i].v))
            i++;
        Union(road[i].u, road[i].v);
        cost += road[i].w;
    }

    return cost;
}
void Union(int a, int b)
{
    p[find(a)] = find(b);
}
int find(int a)
{
    return a == p[a] ? a : (p[a] = find(p[a]));
}