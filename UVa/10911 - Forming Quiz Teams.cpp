#include<cstdio>
#include<cmath>
#define MIN(a,b) ((a)<(b)?(a):(b))

struct Student
{
    int x, y;
    double getDis(Student& p)
    {
        return sqrt((x - p.x)*(x - p.x) + (y - p.y)*(y - p.y));
    }

}student[16];

int main()
{
    int n, i, Case = 1;
    double dp[1 << 16], dis[16][16];

    while (scanf("%d", &n) && n)
    {
        n <<= 1;
        for (i = 0; i < n; i++)
            scanf("%*s%d%d", &student[i].x, &student[i].y);

        for (i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                dis[i][j] = student[i].getDis(student[j]);

        dp[0] = 0;
        //s = set of student, 二進位集合
        for (int s = 1; s < (1 << n); s++) 
        {
            dp[s] = 1e9;
            for (i = n - 1; i >= 0; i--)//最前面的元素，也就是要配對的
                if (s&(1 << i))
                    break;

            for (int j = 0; j < i; j++)//窮舉 i 右邊的元素來配對
                if (s&(1 << j))
                    dp[s] = MIN(dp[s], dis[j][i] + dp[s ^ (1 << i) ^ (1 << j)]);
        }

        printf("Case %d: %.2lf\n", Case++, dp[(1 << n) - 1]);
    }

    return 0;
}