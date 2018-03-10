#include <cstdio>
#include <algorithm>
#define N 101
#define R 10005

struct edge
{
    int u, v, w;
};
int p[N];

inline void init(int n)
{
    for (int i = 0; i <= n; i++)
        p[i] = i;
}
inline int find(int x)
{
    return (x == p[x]) ? x : (p[x] = find(p[x]));
}
inline void Union(int a, int b)
{
    p[find(a)] = find(b);
}
int main()
{
    edge e[R];
    int n, r, Case = 1;
    while (scanf("%d%d", &n, &r) && (n || r))
    {
        r <<= 1;
        for (int i = 0; i < r; i += 2)
        {
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            e[i].u = e[i + 1].v = u;
            e[i].v = e[i + 1].u = v;
            e[i].w = e[i + 1].w = w - 1; //include tourist guide
        }

        int beg, end, all, ans;
        scanf("%d%d%d", &beg, &end, &all);

        //由大排到小
        std::sort(e, e + r, [](const edge &a, const edge &b) -> bool { return a.w > b.w; });

        //kruskal
        init(n);
        for (int i = 0, j = 0; i < n - 1 && j < r; ++i)
        {
            while (find(e[j].u) == find(e[j].v))
                ++j;

            Union(e[j].u, e[j].v);

            //已經找到起點到終點的路徑
            if (find(beg) == find(end))
            {
                ans = e[j].w; //先前建的邊一定比現在大
                break;
            }
        }

        printf("Scenario #%d\n", Case++);
        printf("Minimum Number of Trips = %d\n\n", all / ans + ((all % ans) ? 1 : 0));
    }

    return 0;
}
