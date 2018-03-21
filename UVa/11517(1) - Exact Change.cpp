/*
dp[i]: 所能湊到的 >= i 的錢中最接近的
    -1: 無法湊到 >= i

amount[i]: >= i 的錢所使用的錢幣數
*/
#include <cstdio>
#include <cstring>
#define N 100

int main()
{
    //freopen("test.out", "w", stdout);
    int T, coin[N];
    int dp[10001], amount[10001];

    scanf("%d", &T);
    while (T--)
    {
        memset(dp, -1, sizeof dp);
        memset(amount, 0, sizeof amount);
        dp[0] = 0;
        int n, price;

        scanf("%d%d", &price, &n);

        for (int i = 0; i < n; ++i)
            scanf("%d", &coin[i]);

        for (int k = 0; k < n; ++k)
        {
            for (int i = price; i; --i)
            {
                int idx = i - coin[k];
                if (idx >= 0)
                {
                    if (dp[idx] != -1) //有辦法湊到 i - coin[k]
                    {
                        int now = dp[idx] + coin[k]; //現在所湊到 >= i 的錢
                        int use = amount[idx] + 1;
                        if (now < dp[i] || dp[i] == -1) //取用最接近 i 的或是 i 還沒被湊出來
                        {
                            dp[i] = now;
                            amount[i] = use;
                        }
                        else if (now == dp[i] && amount[i] > use) //採用錢幣數較少的
                            amount[i] = use;
                    }
                }
                else if (dp[i] == -1 || dp[i] >= coin[k])//當前幣值大於 i
                {
                    dp[i] = coin[k];
                    amount[i] = 1;
                }
            }
        }

        printf("%d %d\n", dp[price], amount[price]);
    }

    return 0;
}