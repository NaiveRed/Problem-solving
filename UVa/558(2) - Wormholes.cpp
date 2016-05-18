#include<cstdio>
#include<algorithm>
#define N 2001
#define MAX 100000000
using namespace std;

int a[N], b[N], t[N];
bool BellmanFord(int n, int m);
int main()
{
    int Case, n, m;
    scanf("%d", &Case);
    while (Case--)
    {
        int i;
        scanf("%d%d", &n, &m);
        for (i = 0; i < m; i++)
            scanf("%d%d%d", &a[i], &b[i], &t[i]);
        puts(BellmanFord(n, m) ? "possible" : "not possible");
    }

    return 0;
}
bool BellmanFord(int n, int m)
{
    int d[N];
    fill(d, d + n, MAX);
    d[0] = 0;

    //bellman ford
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < m; j++)
            if (d[a[j]] != MAX)
                if (d[a[j]] + t[j] < d[b[j]])
                    d[b[j]] = d[a[j]] + t[j];

    //negative cycle check
    for (int j = 0; j < m; j++)
        if (d[a[j]] + t[j] < d[b[j]])
            return true;

    return false;
}