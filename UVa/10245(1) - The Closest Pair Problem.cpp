#include<cstdio>
#include<algorithm>
#include<cmath>
struct Point
{
    double x, y;
    double getLen(const Point& a)
    {
        return sqrt((a.x - x)*(a.x - x) + (a.y - y)*(a.y - y));
    }

}point[10000];
int main()
{
    int n, i;
    while (scanf("%d", &n) && n)
    {
        for (i = 0; i < n; i++)
            scanf("%lf%lf", &point[i].x, &point[i].y);

        std::sort(point, point + n, [](const Point& a, const Point& b)->bool{return a.x < b.x; });

        double ans = 10000;
        for (i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
            {
            if (point[i].x + ans < point[j].x)//距離大於 此點 + 目前最短距離，兩點距離不可能小於目前最短距離
                break;
            double d = point[i].getLen(point[j]);
            if (d < ans)
                ans = d;
            }

        if (ans == 10000)
            puts("INFINITY");
        else
            printf("%.4lf\n", ans);
    }

    return 0;
}