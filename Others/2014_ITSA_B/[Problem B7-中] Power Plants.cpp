#include<cstdio>
#include<algorithm>
using namespace std;
#define N 4000
#define M 16000//猜測資不到4000個點...所以AC了
struct Coord
{
    int x, y;
}coord[N];
struct Edge
{
    int a, b, len;
}edge[M];

int p[N];
inline bool compc(const Coord& a, const Coord& b);
inline bool comp(const Edge& a, const Edge& b);
inline void Union(int a, int b);
inline void init(int n, int m);
inline int find(int a);
int kruskal(int n, int m, int e);
int main()
{
    int Case;
    scanf("%d", &Case);

    Edge min[N];
    while (Case--)
    {
        int n, m, i, j;
        scanf("%d%d", &n, &m);
        for (i = 0; i < m; i++)
            scanf("%d%d", &coord[i].x, &coord[i].y);
        for (; i < n; i++)
            scanf("%d%d", &coord[i].x, &coord[i].y);
     
        int  x, y;
        for (i = 0; i < n; i++)
            min[i].len = 1e9;
        for (i = m; i < n; i++)
        {
            for (j = 0; j < m; j++)
            {
                x = coord[i].x - coord[j].x;
                y = coord[i].y - coord[j].y;
                if (min[i].len > (x >= 0 ? x : -x) + (y >= 0 ? y : -y))
                {
                    min[i].len = (x >= 0 ? x : -x) + (y >= 0 ? y : -y);
                    min[i].a = i;
                    min[i].b = j;
                }
            }
        }

        for (i = 0; i < n; i++)
            edge[i] = min[i];
        int count = i;
        sort(coord + m - 1, coord + n, compc);
        for (i = m; i < n; i++)
        {
            for (j = i + 1; j < n; j++)
            {
                if (coord[i].x + min[i].len < coord[j].x)
                    break;
                edge[count].a = i;
                edge[count].b = j;
                x = coord[i].x - coord[j].x;
                y = coord[i].y - coord[j].y;
                edge[count++].len = (x >= 0 ? x : -x) + (y >= 0 ? y : -y);
            }
        }
        
        printf("%d\n", kruskal(n, m, count));
    }

    return 0;
}
int kruskal(int n, int m, int e)
{
    int sum = 0;
    init(n, m);
    sort(edge, edge + e, comp);

    for (int i = 0, j = 0; i < n - m&&j < e; i++, j++)
    {
        while (find(edge[j].a) == find(edge[j].b))
            j++;

        Union(edge[j].a, edge[j].b);
        sum += edge[i].len;
    }

    return sum;
}
bool comp(const Edge& a, const Edge& b)
{
    return a.len < b.len;
}
bool compc(const Coord& a, const Coord& b)
{
    return a.x < b.x;
}
void Union(int a, int b)
{
    p[find(a)] = find(b);
}
void init(int n, int m)
{
    int i;
    for (i = 0; i < m; i++)
        p[i] = 0;
    for (; i < n; i++)
        p[i] = i;
}
int find(int a)
{
    return p[a] == a ? a : (p[a] = find(p[a]));
}