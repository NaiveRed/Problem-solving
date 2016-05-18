#include<cstdio>

int main()
{
    int n, m;
    while (scanf("%d%d", &n, &m) && n)
    {
        if (n - m < m)//使乘的次數變少，以免超時
            m = n - m;
        double ans = 1;
        for (int i = n, j = 1; j <= m; j++,i--)
        {
            ans *= i;
            ans /= j;//從小的開始除，最終答案是整數，所以最後一定除的盡
        }
        printf("%.0lf\n", ans);
    }

    return 0;
}