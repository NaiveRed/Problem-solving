#include <cstdio>

int main()
{
    int Case;
    scanf("%d", &Case);

    int item[21][21] = {};
    while (Case--)
    {
        int M, C;
        scanf("%d%d", &M, &C);
        for (int i = 1; i <= C; i++)
        {
            scanf("%d", &item[i][0]);
            for (int k = 1; k <= item[i][0]; k++)
                scanf("%d", &item[i][k]);
        }

        bool dp[21][201] = {true};

        /*
        dp[0][0] = true
        dp[i][m] =
        true: 有辦法買第 1 ~ i 種服飾後，會花費剛好 m
        false: 無法湊成 m
        */
        for (int i = 1; i <= C; i++)
        {
            //每種服飾有數種價錢
            for (int k = 1; k <= item[i][0]; k++)
                for (int m = M; m >= item[i][k]; m--)
                    dp[i][m] |= dp[i - 1][m - item[i][k]];
        }

        int ans;
        //找花費最多的買法
        for (ans = M; ans >= 0 && !dp[C][ans]; ans--)
            ;

        if (ans >= 0)
            printf("%d\n", ans);
        else
            puts("no solution");
    }

    return 0;
}