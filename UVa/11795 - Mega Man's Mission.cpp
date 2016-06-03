#include<cstdio>
#include<algorithm>
#define N 1<<16
using namespace std;

int main()
{
    long long dp[N];//當前集合的次數
    int state[N];//當前能擊敗的集合
    int Case;
    char str[17];

    scanf("%d", &Case);

    for (int c = 1; c <= Case; c++)
    {
        int n, i, j;
        int robot[17] = {};//0 為 mega buster,其餘為擊敗此 robot[] 後，可以打倒的其他 robot 集合

        scanf("%d", &n);
        getchar();
        fill(state, state + (1 << n), 0);
        fill(dp, dp + (1 << n), 0);

        for (i = 0; i <= n; i++)
        {
            gets(str);
            //讓第一個存在 LSB
            int r = 1;
            for (j = 0; j < n; j++)
            {
                if (str[j] == '1')
                    robot[i] |= r;
                r <<= 1;
            }
        }

        //init
        state[0] = robot[0];
        dp[0] = 1;

        int all = 1 << n;//全部的組合
        for (i = 0; i < all; i++)
        {
            /*
            i = 為當前已走的(集合)
            ~i = 則為還沒走的
            state[i] = 當前集合可以走的
            */
            int ok = (~i)&state[i];//未走且可走的
            
            //選擇要擊倒哪個
            int r = 1;
            for (j = 1; j <= n; j++)
            {
                if (ok&r)
                {
                    /*
                    r | i 為擊倒完後的集合
                    */
                    dp[r | i] += dp[i];//次數計算
                    //擊倒完後的 state 集合 ，變成 "未擊倒前的" 加上(or) "擊倒後才可以的"
                    state[r | i] = state[i] | robot[j];
                }

                r <<= 1;//換下一個
            }
        }

        printf("Case %d: %lld\n", c, dp[all - 1]);
    }

    return 0;
}