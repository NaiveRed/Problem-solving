#include<cstdio>
#include<algorithm>
#include<cmath>
#define N 100000
#define MAX 1e9
using namespace std;
struct Point
{
    int x, y;
    int getSide(const Point& a){ return max(abs(x - a.x), abs(y - a.y)); }

}point[N];

int DnC(int L, int R);
int main()
{
    int n;
    while (scanf("%d", &n) != EOF)
    {
        int i, j;
        for (i = 0; i < n; i++)
            scanf("%d%d", &point[i].x, &point[i].y);

        sort(point, point + n, [](const Point& a, const Point& b)->bool{return a.x < b.x; });

        printf("%d\n", DnC(0, n - 1));
    }

    return 0;
}
int DnC(int L, int R)
{
    if (L >= R)
        return MAX;
    else if (R - L < 3)
    {
        int d = MAX;
        for (int i = L; i < R; i++)
            for (int j = i + 1; j <= R; j++)
                d = min(d, point[i].getSide(point[j]));
        return d;
    }

    int M = (L + R) >> 1, i, j;

    int d = min(DnC(L, M), DnC(M + 1, R));
    //每個左側的點，到右側的點
    for (i = M; i >= L; i--)
    {
        if (point[M].x - point[i].x >= d)
            break;
        for (j = M + 1; j <= R; j++)
        {
            if (point[j].x - point[M].x >= d)
                break;
            int temp = point[i].getSide(point[j]);
            if (temp < d)
                d = temp;
        }
    }

    return d;
}