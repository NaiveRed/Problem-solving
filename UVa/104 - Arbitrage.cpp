#include<cstdio>
#include<stack>
using namespace std;
#define N 21

double d[N][N][N];
int path[N][N][N];
void FloydWarshall(int n);
int main()
{
    int n, i, j;
    while (scanf("%d", &n) != EOF)
    {
        for (i = 1; i <= n; i++)
            for (j = 1; j <= n; j++)
            {
            if (i == j)
                d[i][j][1] = 1;
            else
                scanf("%lf", &d[i][j][1]);
            path[i][j][1] = i;
            }

        FloydWarshall(n);
    }

    return 0;
}
void FloydWarshall(int n)
{
    int i, j, k;
    for (k = 2; k <= n; k++)
        for (i = 1; i <= n; i++)
            for (j = 1; j <= n; j++)
                path[i][j][k] = d[i][j][k] = 0;

    for (int step = 2; step <= n; step++)
    {
        for (k = 1; k <= n; k++)
            for (i = 1; i <= n; i++)
                for (j = 1; j <= n; j++)
                {
            if (d[i][k][step - 1] * d[k][j][1] > d[i][j][step])
            {
                d[i][j][step] = d[i][k][step - 1] * d[k][j][1];
                path[i][j][step] = k;
            }
                }

        for (i = 1; i <= n; i++)
        {
            if (d[i][i][step] > 1.01)
            {
                stack<int> s;
                j = i;
                while (step-1)
                    s.push(j = path[i][j][step--]);
                
                printf("%d ", i);
                while (!s.empty())
                {
                    printf("%d ", s.top());
                    s.pop();
                }
                printf("%d\n", i);

                return;
            }
        }
    }

    puts("no arbitrage sequence exists");
    return;
}