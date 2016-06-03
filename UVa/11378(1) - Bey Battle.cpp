#include<cstdio>
#include<algorithm>
#include<cmath>
#define N 100000
using namespace std;
struct Point
{
    int x, y;
    int getSide(const Point& a){ return max(abs(x - a.x), abs(y - a.y)); }

}point[N];
int main()
{
    int n;
    while (scanf("%d", &n) != EOF)
    {
        int i, j;
        for (i = 0; i < n; i++)
            scanf("%d%d", &point[i].x, &point[i].y);

        sort(point, point + n, [](const Point& a, const Point& b)->bool{return a.x < b.x; });
        int min = 1e9;
        for (i = 0; i < n; i++)
        {
            for (j = i + 1; j < n; j++)
            {
                if (point[i].x + min < point[j].x)
                    break;

                int temp = point[i].getSide(point[j]);
                if (temp < min)
                    min = temp;
            }
        }

        printf("%d\n", min);
    }

    return 0;
}
