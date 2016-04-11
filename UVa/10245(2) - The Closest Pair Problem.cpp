#include<cstdio>
#include<algorithm>
#include<cmath>
#define N 10000
#define MAX 10000
using namespace std;

struct Point
{
    double x, y;
    double getLen(const Point& a)
    {
        return sqrt((a.x - x)*(a.x - x) + (a.y - y)*(a.y - y));
    }

}point[N];

double DnC(int L, int R);
int main()
{
    int n, i;
    while (scanf("%d", &n) && n)
    {
        for (i = 0; i < n; i++)
            scanf("%lf%lf", &point[i].x, &point[i].y);

        sort(point, point + n, [](const Point& a, const Point& b)->bool{return a.x < b.x; });

        double ans = DnC(0, n - 1);

        if (ans == 10000)
            puts("INFINITY");
        else
            printf("%.4lf\n", ans);

    }

    return 0;
}
double DnC(int L, int R)
{
    int i, j;
    if (L >= R)//只有一個點
        return MAX;
    else if (R - L < 3)//2 或 3 個點
    {
        double d = MAX;
        for (i = L; i < R; i++)
            for (j = i + 1; j <= R; j++)
                d = min(d, point[i].getLen(point[j]));
        return d;
    }

    int M = (L + R) / 2;

    //左右兩側的最短距離
    double d = min(DnC(L, M), DnC(M + 1, R));
    if (d == 0)
        return 0;

    int n = 0;
    Point strip[N];
    //尋找靠近中線的點，離中線小於目前最短距離 d
    for (i = M; i >= L&&point[M].x - point[i].x < d; i--)
        strip[n++] = point[i];
    for (i = M + 1; i <= R&&point[i].x - point[M].x < d; i++)
        strip[n++] = point[i];

    //依 y 軸排序
    sort(strip, strip + n, [](const Point& a, const Point& b)->bool{return a.y < b.y; });

    //找出橫跨兩側的最短距離
    for (i = 0; i < n; i++)
        for (j = 1; j <= 3 && i + j < n; j++)
            d = min(d, strip[i].getLen(strip[i + j]));

    return d;
}