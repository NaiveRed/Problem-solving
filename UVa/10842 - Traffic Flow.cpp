#include<cstdio>
#include<algorithm>

struct Road
{
    int u, v, c;
}road[10001];

int p[101], rank[101];
inline void init(int n);
inline int find(int n);
inline void Union(int a, int b);
int kruskal(int V, int E);
int main()
{
    int Case;
    scanf("%d", &Case);

    for (int c = 1; c <= Case; c++)
    {
        int n, m;
        scanf("%d%d", &n, &m);

        for (int i = 0; i < m; i++)
            scanf("%d%d%d", &road[i].u, &road[i].v, &road[i].c);

        printf("Case #%d: %d\n", c, kruskal(n, m));
    }

    return 0;
}
inline void init(int n)
{
    for (int i = 0; i < n; i++)
    {
        p[i] = i;
        rank[i] = 0;
    }
}
inline int find(int n)
{
    return p[n] == n ? n : (p[n] = find(p[n]));
}
inline void Union(int a, int b)
{
    a = find(a);
    b = find(b);
    if (rank[a]>rank[b])
        p[b] = a;
    else if (rank[a] < rank[b])
        p[a] = b;
    else
    {
        p[a] = b;
        rank[b]++;
    }
}
int kruskal(int V, int E)
{
    init(V);
    std::sort(road, road + E, [](const Road& a, const Road& b)->bool{return a.c > b.c; });

    int capacity = 0;
    for (int i = 0, e = 0; i < E&&e < V - 1; i++)
    {
        while (find(road[i].u) == find(road[i].v))
            i++;

        Union(road[i].u, road[i].v);
        e++;

        if (e == V - 1)
            capacity = road[i].c;//保留的路中，capacity 最小的
    }

    return capacity;
}