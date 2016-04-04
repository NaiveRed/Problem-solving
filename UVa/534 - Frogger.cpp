#include<cstdio>
#include<cmath>
#include<queue>
#define MAX(a,b) ((a)>(b)?(a):(b))
#define N 201
using namespace std;

struct Coord
{
    int x, y;
    float getDistance(Coord& a)
    {
        return sqrt((x - a.x)*(x - a.x) + (y - a.y)*(y - a.y));
    }

}stone[N];

float SPFA(int n);
int main()
{
    int n, i, Case = 1;
    while (scanf("%d", &n) && n)
    {
        //第 0 和 1 分別為起點和終點
        for (i = 0; i < n; i++)
            scanf("%d%d", &stone[i].x, &stone[i].y);

        printf("Scenario #%d\nFrog Distance = %.3f\n\n", Case++, SPFA(n));
    }

    return 0;
}
float SPFA(int n)
{
    int i;
    float d[N] = { 0 };
    bool inQ[101] = {};
    queue<int> Q;
    for (i = 1; i < n; i++)
        d[i] = 1e9;

    Q.push(0);

    while (!Q.empty())
    {
        int idx = Q.front();
        Q.pop();

        inQ[idx] = false;

        for (i = 1; i < n; i++)
        {
            //比較從起點到 idx 和 從 idx 到 i ，兩個的 minmax distance，較大的則為這條路徑(從起點到 i )的 minmax distance
            float max = MAX(d[idx], stone[idx].getDistance(stone[i]));
           
            //看是否有比原本的 minmax distance 小
            if (max < d[i])
            {
                d[i] = max;
                if (!inQ[i])
                {
                    Q.push(i);
                    inQ[i] = true;
                }
            }
        }
    }

    return d[1];
}