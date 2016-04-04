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
        //�� 0 �M 1 ���O���_�I�M���I
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
            //����q�_�I�� idx �M �q idx �� i �A��Ӫ� minmax distance�A���j���h���o�����|(�q�_�I�� i )�� minmax distance
            float max = MAX(d[idx], stone[idx].getDistance(stone[i]));
           
            //�ݬO�_����쥻�� minmax distance �p
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