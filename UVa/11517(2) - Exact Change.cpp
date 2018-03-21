#include <cstdio>
#include <cstring>
#define N 100
#define P 10001

int main()
{
    //freopen("test.out", "w", stdout);
    int T, coin[N];
    bool dp[P];
    int amount[P]= {};

    scanf("%d", &T);
    while (T--)
    {
        memset(dp, false, sizeof dp);

        dp[0] = true;
        int n, price;

        scanf("%d%d", &price, &n);

        for (int i = 0; i < n; ++i)
            scanf("%d", &coin[i]);

        for(int i=1; i<P; ++i)
            amount[i]=1e9;

        for (int k = 0; k < n; ++k)
            for (int i = P-1; i>=coin[k]; --i)
            {
                if(dp[i-coin[k]])
                {
                    dp[i] = true;
                    if(amount[i]>amount[i-coin[k]]+1)
                        amount[i] = amount[i-coin[k]]+1;
                }
            }

        for(int i=price; i<P; ++i)
        {
            if(dp[i])
            {
                printf("%d %d\n", i, amount[i]);
                break;
            }
        }
    }

    return 0;
}
