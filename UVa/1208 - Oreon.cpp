//不用照字母序去輸出也能 AC
#include <cstdio>
#include <algorithm>
#define N 700
#define A 26
struct edge
{
    int u, v, w;
    bool operator<(const edge &a) const
    {
        return w < a.w;
    }
} E[N];

//disjoint set
int p[26];
inline void init(int n)
{
    for (int i = 0; i < n; ++i)
        p[i] = i;
}
inline int find(int x)
{
    return (x == p[x]) ? x : (p[x] = find(p[x]));
}
inline void do_union(int x, int y)
{
    p[find(x)] = find(y);
}

int main()
{
    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; ++t)
    {
        int n, count = 0, tmp;
        scanf("%d", &n);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
            {
                scanf("%d%*c", &tmp);
                if (j <= i || !tmp) //前面已輸入過(雙向)、自己到自己或沒有通道
                    continue;

                E[count].u = i;
                E[count].v = j;
                E[count++].w = tmp;
            }

        printf("Case %d:\n", t);

        //kruskal
        init(n);
        std::sort(E, E + count);
        for (int i = 0, e = 0; i < count && e < n - 1; ++i, ++e)
        {
            //找在不同樹上的
            while (find(E[i].u) == find(E[i].v))
                ++i;

            do_union(E[i].u, E[i].v);
            printf("%c-%c %d\n", E[i].u + 'A', E[i].v + 'A', E[i].w);
        }
    }

    return 0;
}