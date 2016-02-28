#include<cstdio>

int main()
{
    int dp[77] = {0,1,2,2};
    for (int i = 4; i < 77; i++)
        dp[i] = dp[i - 2] + dp[i - 3];

    int n;
    while (scanf("%d", &n) != EOF)
        printf("%d\n", dp[n]);

    return 0;
}