#include <cstdio>
#include <cstring>
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define N 601

int main()
{
    //freopen("test.out", "w", stdout);
    const int coin[6] = {5, 10, 20, 50, 100, 200};
    int have[6];
    int dp[N] = {};       //the number of coins
    int change[201] = {}; //該數目零錢所需的錢幣數(除不盡的零錢數在本題不會使用到)
    for (int i = 5; i < 201; ++i)
    {
        int back = i;
        for (int k = 5; k >= 0 && back; --k)
        {
            change[i] += back / coin[k];
            back %= coin[k];
        }
    }

    while (scanf("%d%d%d%d%d%d", &have[0], &have[1], &have[2], &have[3], &have[4], &have[5]))
    {
        int sum = 0;
        for (int i = 0; i < 6; ++i)
            sum += coin[i] * have[i];
        if (!sum)
            return 0;

        int a, b, price;
        scanf("%d.%d", &a, &b);
        price = a * 100 + b;

        for (int i = 1; i < N; ++i)
            dp[i] = 1e9;

        for (int i = 0; i < 6; ++i)
            for (int k = have[i]; k; --k)
                for (int p = MIN(600, sum); p >= coin[i]; --p)
                {
                    int tmp = p - coin[i];
                    if (dp[tmp] < 1e9)
                        dp[p] = MIN(dp[tmp] + 1, dp[p]);
                }

        //最多 500，但可以用 3*200 = 600 來付
        int min = 1e9;
        for (int p = MIN(600, sum); p >= price; --p)
        {
            if (dp[p] < 1e9)
            {
                if (p > price)
                    dp[p] += change[p - price];

                if (dp[p] < min)
                    min = dp[p];
            }
        }

        printf("%3d\n", min);
    }

    return 0;
}