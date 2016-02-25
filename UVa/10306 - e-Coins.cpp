#include<cstdio>
#define MIN(a,b) ((a)<(b)?(a):(b))

struct ECoin
{
    int c;//conventional value
    int tech;//InfoTechnological value

}coin[41];

int solve(int n, int modulus);
int main()
{
    int Case;
    scanf("%d", &Case);

    while (Case--)
    {
        int n, modulus, i;
        scanf("%d%d", &n, &modulus);
        for (i = 0; i < n; i++)
            scanf("%d%d", &coin[i].c, &coin[i].tech);

        int ans = solve(n, modulus);
        if (ans > 300)
            puts("not possible");
        else
            printf("%d\n", ans);
    }

    return 0;
}
int solve(int n, int modulus)
{
    int dp[301][301] = {}, tar = modulus*modulus;
    int i, j;

    //init
    for (i = 0; i <= modulus; i++)
        for (j = 0; j <= modulus; j++)
            dp[i][j] = 301;
    
    //方便待會做DP
    dp[0][0] = 0;

    //DP，計算 e-modulus 所需的 e-coin 數量
    for (i = 0; i < n; i++)
    {
        int c = coin[i].c, tech = coin[i].tech;
        for (int x = c; x*x + tech*tech <= tar; x++)
            for (int y = tech; x*x + y*y <= tar; y++)
                dp[x][y] = MIN(dp[x][y], dp[x - c][y - tech] + 1);
    }

    //找出最小的湊法
    int min = 301;
    for (i = 0; i <= modulus; i++)
        for (j = 0; j <= modulus; j++)
            if (i*i + j*j == tar)
                if (min>dp[i][j])
                    min = dp[i][j];

    return min;
}