#include<cstdio>
#include<algorithm>
using namespace std;

struct Point
{
    int x, y;
};
struct Line
{
    Point a, b;
};
inline int cross(Point& a, Point& b1, Point& b2)//(a->b1) x (a->b2)
{
    int x1 = b1.x - a.x, y1 = b1.y - a.y;
    int x2 = b2.x - a.x, y2 = b2.y - a.y;

    return x1*y2 - x2*y1;
}
inline bool intersect1D(int a1, int a2, int b1, int b2)
{
    if (a1 > a2)
        swap(a1, a2);
    if (b1 > b2)
        swap(b1, b2);

    return max(a1, b1) <= min(a2, b2);
}
inline bool intersect(Line& L1, Line& L2)
{
    return intersect1D(L1.a.x, L1.b.x, L2.a.x, L2.b.x) //x 軸投影相交
        && intersect1D(L1.a.y, L1.b.y, L2.a.y, L2.b.y) //y 軸投影相交
        && cross(L1.a, L1.b, L2.a)*cross(L1.a, L1.b, L2.b) <= 0 
        && cross(L2.a, L2.b, L1.a)*cross(L2.a, L2.b, L1.b) <= 0;
}
Line line[13];
int main()
{
    int Case;
    bool d[13][13] = {};

    scanf("%d", &Case);
    while (Case--)
    {
        int n, i, j;
        scanf("%d", &n);
        for (i = 0; i < n; i++)
            scanf("%d%d%d%d", &line[i].a.x, &line[i].a.y, &line[i].b.x, &line[i].b.y);

        //init
        for (i = 0; i < n; i++)
            for (j = 0; j < n; j++)
                d[i][j] = false;
        for (i = 0; i < n; i++)
            d[i][i] = true;

        //build graph
        for (i = 0; i < n; i++)
            for (j = i + 1; j < n; j++)
                if (intersect(line[i], line[j]))
                    d[j][i] = d[i][j] = true;

        //Floyd-Warshall
        for (int k = 0; k < n; k++)
            for (i = 0; i < n; i++)
                for (j = 0; j < n; j++)
                    if (i != j&&d[i][k] && d[k][j] && !d[i][j])
                        d[i][j] = true;

        while (scanf("%d%d", &i, &j) && i)
                puts(d[i - 1][j - 1] ? "CONNECTED" : "NOT CONNECTED");
        
        if (Case)
            putchar('\n');
    }

    return 0;
}