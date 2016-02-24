//C++11
#include<cstdio>
#include<cmath>
#include<algorithm>
#define B 751

struct Coord
{
    int x, y;
    inline double getLength(Coord &a);
};
struct Edge
{
    //��ؿv���M�������Z��
    int a, b;
    double w;
};

int p[B];
Edge edge[300000];
inline void init(int n);
inline int find(int a);
inline void Union(int a, int b);
double kruskal(int N, int E);//(���s�X����,�`�@���X����)
int main()
{
    int N, M, i;
    Coord building[B];

    while (scanf("%d", &N) != EOF)
    {
        for (i = 1; i <= N; i++)
            scanf("%d%d", &building[i].x, &building[i].y);

        //init disjoint-set
        init(N);

        int a, b, connect = 0;
        scanf("%d", &M);
        for (i = 0; i < M; i++)
        {
            scanf("%d%d", &a, &b);
            if (find(a) != find(b))
            {
                Union(a, b);
                connect++;//�w�g�s���n���u
            }
        }

        int E = 0;
        for (i = 1; i <= N; i++)
            for (int j = i + 1; j <= N; j++)
            {
            if (find(i) != find(j))//�P�_�O�_�|�]�쥻���n��������
            {
                edge[E].a = i;
                edge[E].b = j;
                edge[E++].w = building[i].getLength(building[j]);
            }
            }

        printf("%.2lf\n", kruskal(N - connect - 1, E));
    }

    return 0;
}
void init(int n)
{
    for (int i = 0; i <= n; i++)
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
double Coord::getLength(Coord& a)
{
    //�Īѩw�z
    double xx = (double)(x - a.x)*(x - a.x);
    double yy = (double)(y - a.y)*(y - a.y);

    return sqrt(xx + yy);
}
double kruskal(int n, int E)
{
    std::sort(edge, edge + E, [](const Edge& a, const Edge& b)->bool{return a.w < b.w; });

    double cost = 0;
    for (int i = 0, e = 0; i < E&&e < n; i++, e++)
    {
        while (find(edge[i].a) == find(edge[i].b))
            i++;

        Union(edge[i].a, edge[i].b);

        cost += edge[i].w;
    }

    return cost;
}

