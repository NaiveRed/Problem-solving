//C++11
#include<cstdio>
#include<algorithm>
#define MAX 1000001

struct Edge
{
    int v1, v2;
    int weight;
}edge[MAX];

//disjoint-set forest
int p[MAX];
inline int find(int a);
//minimum spanning tree
int kruskal(int N, int E);
int main()
{
    int N;
    bool first = true;
    while (scanf("%d", &N) != EOF)
    {
        int i, a, b, w;
        int old_cost = 0, new_cost;
        for (i = 1; i < N; i++)
        {
            scanf("%d%d%d", &a, &b, &w);
            old_cost += w;
        }

        int K, M;
        scanf("%d", &K);
        for (i = 0; i < K; i++)
            scanf("%d%d%d", &edge[i].v1, &edge[i].v2, &edge[i].weight);

        scanf("%d", &M);
        for (i = 0; i < M; i++)
            scanf("%d%d%d", &edge[i + K].v1, &edge[i + K].v2, &edge[i + K].weight);

        new_cost = kruskal(N, K + M);

        if (first)
            first = false;
        else
            putchar('\n');
        printf("%d\n%d\n", old_cost, new_cost);
    }

    return 0;
}
int kruskal(int N, int E)
{
    int i;
    //init
    for (i = 0; i <= N; i++)
        p[i] = i;

    std::sort(edge, edge + E,
        [](const Edge& a, const Edge& b)->bool{return a.weight < b.weight; }
    );

    int e, cost = 0;
    for (i = 0, e = 0; i < E&&e < N - 1; e++, i++)
    {
        //判斷是否會成為環
        while (find(edge[i].v1) == find(edge[i].v2))i++;

        //union
        p[find(edge[i].v1)] = find(edge[i].v2);

        //count cost
        cost += edge[i].weight;
    }

    return cost;
}
int find(int a)
{
    return a == p[a] ? a : (p[a] = find(p[a]));
}
