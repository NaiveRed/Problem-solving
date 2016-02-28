#include<cstdio>
#include<cmath>
#include<climits>
#define N 101

struct Point
{
    double x, y;

    double getDistance(const Point& a)
    {
        return sqrt((x - a.x)*(x - a.x) + (y - a.y)*(y - a.y));
    }

}point[N];

double prim(int n);
int main()
{
    int Case;
    scanf("%d", &Case);

    int M[N][N] = {};
    while (Case--)
    {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%lf%lf", &point[i].x, &point[i].y);

        printf("%.2lf\n", prim(n));
        if (Case)
            putchar('\n');
    }

    return 0;
}
double prim(int n)
{
    bool isVisit[N] = {};
    double w[N][N] = {}, d[N];
    double sum = 0;

    //建 adjacency matrix
    int i, j;
    for (i = 0; i < n; i++)
        for (j = i + 1; j < n; j++)
            w[j][i] = w[i][j] = point[i].getDistance(point[j]);

    //從 0 開始走
    for (i = 0; i < n; i++)
        d[i] = w[0][i];
    isVisit[0] = true;

    for (i = 0; i < n; i++)
    {
        //找離樹最近的點
        int next = -1;
        double min = INT_MAX;
        for (j = 0; j < n; j++)
            if (d[j] < min&&!isVisit[j])
            {
            min = d[j];
            next = j;
            }

        //已經沒有離樹最近的點了
        if (next == -1)
            break;

        sum += min;
        isVisit[next] = true;

        //根據新加入的點，更新樹到各點的最短距離
        for (j = 0; j < n; j++)
            if (w[next][j] < d[j])
                d[j] = w[next][j];
    }

    return sum;
}