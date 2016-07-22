#include<cstdio>
#include<iostream>
#include<queue>
#include<map>
#include<string>
#define MIN(a,b) ((a)<(b)?(a):(b))
#define N 201
using namespace std;

int adjM[N][N] = {};
int SPFA(int n, int st, int end);
int main()
{
    int n, r, i, j, Case = 1;

    while (scanf("%d%d", &n, &r) && n)
    {
        map<string, int> city;
        string str1, str2;
        int count = 0, a, b, w;
        for (i = 0; i <= n; i++)
            for (j = 0; j <= n; j++)
                adjM[i][j] = 0;

        for (i = 0; i < r; i++)
        {
            cin >> str1 >> str2 >> w;
            if (!city.count(str1))
                city[str1] = ++count;
            if (!city.count(str2))
                city[str2] = ++count;

            a = city[str1];
            b = city[str2];

            adjM[b][a] = adjM[a][b] = w;
        }

        cin >> str1 >> str2;
        printf("Scenario #%d\n", Case++);
        printf("%d tons\n\n", SPFA(n, city[str1], city[str2]));
    }

    return 0;
}
int SPFA(int n, int st, int end)
{
    queue<int> Q;
    int weight[N] = {};
    bool inQ[N] = {};
    Q.push(st);

    while (!Q.empty())
    {
        int u = Q.front();
        Q.pop();
        inQ[u] = false;

        for (int v = 1; v <= n; v++)
            if (adjM[u][v])
            {
                int maxW = weight[u] ? MIN(adjM[u][v], weight[u]) : adjM[u][v];//兩段路 (st->u->v) 中可負載的最大為，兩段中較小的

                if (maxW > weight[v])//看似否比原先路段 (st->v) 中的負載能力高
                {
                    weight[v] = maxW;
                    if (!inQ[v])
                    {
                        Q.push(v);
                        inQ[v] = true;
                    }
                }
            }
    }

    return weight[end];
}