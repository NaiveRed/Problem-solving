#include<stdio.h>
#define MAX(a,b) ((a)>(b)?(a):(b))

int main()
{
    int Case, num[100], dp[50001];
    scanf("%d", &Case);
    while (Case--)
    {
        int n, i, k, sum = 0;
        scanf("%d", &n);
        for (i = 0; i < n; i++)
        {
            scanf("%d", &num[i]);
            sum += num[i];
        }

        int half = sum >> 1;
        for (i = 0; i <= half; i++)
            dp[i] = 0;

        //從一半開始做 dp ，dp[k] 表此時可以湊到的最多錢數 小於等於 k
        for (i = 0; i < n; i++)
            for (k = half; k >= num[i]; k--)//不重複使用，top-down
                dp[k] = MAX(dp[k], dp[k - num[i]] + num[i]);

        printf("%d\n", (sum - dp[half]) - dp[half]);//大於等於一半的 = sum - dp[half]，在減掉 dp[half] 即是相差的了
    }

    return 0;
}