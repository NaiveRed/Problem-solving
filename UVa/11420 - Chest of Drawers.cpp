#include <cstdio>

int main()
{
    int n, s;
    long long dp[66][67][2] = {}; //0: unlock, 1: lock

    dp[1][0][0] = 1;
    dp[1][1][1] = 1;

    /*        
    dp[1][1][0] = 0
    dp[1~n][0][1] = 0
    dp[i][j][0] = 0 , if (j > i)
      
    s  s-1 s+1 s+1
    U   U   L   L | n
    --------------|
    U   L   U   L | n-1,s
    */
    for (int i = 2; i < 66; i++)
    {
        dp[i][0][0] = dp[i - 1][1][1] + dp[i - 1][0][0];
        for (int j = 1; j <= i; j++)
        {
            dp[i][j][0] = dp[i - 1][j + 1][1] + dp[i - 1][j][0];
            dp[i][j][1] = dp[i - 1][j - 1][1] + dp[i - 1][j - 1][0];
        }
    }

    while (scanf("%d%d", &n, &s) && (n >= 0 || s >= 0))    
        printf("%lld\n", dp[n][s][0] + dp[n][s][1]);    

    return 0;
}