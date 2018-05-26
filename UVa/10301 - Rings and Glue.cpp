#include <cstdio>
#include <cmath>
#define N 100

struct circle
{
    float x, y, r;

    bool intersect(const circle &c)
    {
        /*
        交於兩點：
        1. 兩圓心距離小於兩圓半徑相加
        2. 兩圓心距離大於兩圓半徑相減(在另一個圓圈內)
        */
        float dis = sqrt((x - c.x) * (x - c.x) + (y - c.y) * (y - c.y));
        return dis < (r + c.r) && dis > abs(r - c.r);
    }
} C[N];

//disjoint set
int p[N], size[N];
inline void init(int n)
{
    for (int i = 0; i < n; ++i)
    {
        p[i] = i;
        size[i] = 1;
    }
}
inline int find(int x)
{
    return (x == p[x]) ? x : (p[x] = find(p[x]));
}
inline void do_union(int x, int y)
{
    x = find(x), y = find(y);
    if (x == y)
        return;

    //小的併入大的
    if (size[x] < size[y])
    {
        p[x] = y;
        size[y] += size[x];
        //size[x] = 0;
    }
    else
    {
        p[y] = x;
        size[x] += size[y];
        //size[y] = 0;
    }
}

int main()
{
    int n;
    while (scanf("%d", &n) && n != -1)
    {
        for (int i = 0; i < n; ++i)
            scanf("%f%f%f", &C[i].x, &C[i].y, &C[i].r);

        init(n);
        for (int i = 0; i < n - 1; ++i)
            for (int j = i + 1; j < n; ++j)
                if (C[i].intersect(C[j]))
                    do_union(i, j);

        int max = 0;
        for (int i = 0; i < n; ++i)
            if (max < size[i])
                max = size[i];
        printf("The largest component contains %d ring%s\n", max, max == 1 ? "." : "s.");
    }

    return 0;
}