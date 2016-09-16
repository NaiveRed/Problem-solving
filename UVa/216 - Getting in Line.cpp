#include<cstdio>
#include<cmath>

struct Point
{
    int x, y;
    double getDis(Point& p)
    {
        return sqrt((x - p.x)*(x - p.x) + (y - p.y)*(y - p.y));
    }

}point[8];
double dis[8][8],min;
int n, seq[8], min_seq[8];
bool visit[8];
void dfs(int prev, int count, double len)
{
    if (count == n)
    {
        if (min > len)
        {
            min = len;
            for (int i = 0; i < n; i++)
                min_seq[i] = seq[i];
        }

        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (!visit[i])
        {
            visit[i] = true;
            seq[count] = i;
            dfs(i, count + 1, len + dis[prev][i]);
            visit[i] = false;
        }
    }
}
int main()
{
    int i, Case = 1;
    while (scanf("%d", &n) && n)
    {
        for (i = 0; i < n; i++)
            scanf("%d%d", &point[i].x, &point[i].y);

        for (i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                dis[i][j] = dis[j][i] = point[i].getDis(point[j]);

        min = 1e9;
        for (i = 0; i < n; i++)
        {
            seq[0] = i;
            visit[i] = true;
            dfs(i, 1, 0);
            visit[i] = false;
        }

        puts("**********************************************************");
        printf("Network #%d\n", Case++);
        for (i = 0; i < n - 1; i++)
            printf("Cable requirement to connect (%d,%d) to (%d,%d) is %.2lf feet.\n", point[min_seq[i]].x, point[min_seq[i]].y, point[min_seq[i + 1]].x, point[min_seq[i + 1]].y, dis[min_seq[i]][min_seq[i + 1]]+16);
        printf("Number of feet of cable required is %.2lf.\n", min+16*(n-1));
    }

    return 0;
}