#include<cstdio>

int main()
{
    int Case, ans[14][14][14] = {};

    ans[1][1][1] = 1;
    for (int n = 2; n < 14; n++)
        for (int p = 1; p <= n; p++)
            for (int r = 1; r <= n; r++)
                ans[n][p][r] = ans[n - 1][p - 1][r] + ans[n - 1][p][r - 1] + ans[n - 1][p][r] * (n - 2);

    scanf("%d", &Case);
    while (Case--)
    {
        int N, P, R;
        scanf("%d%d%d", &N, &P, &R);        
        printf("%d\n", ans[N][P][R]);
    }

    return 0;
}