#include <cstdio>
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define N 301

int main()
{
    //freopen("test.out","w",stdout);
    //freopen("test.in","r",stdin);
    //最多 300 個 1 元
    long long DP[N][N] = {1}; //DP[n][x] = 用 x 個錢幣湊成 n 元的方法數

    for (int coin = 1; coin < N; ++coin) //幣值
        for (int p = coin; p < N; ++p)   //總價
            for (int k = 1; k <= p; ++k) //總錢幣個數            
                DP[p][k] += DP[p - coin][k - 1];                            

    char str[20];
    while (fgets(str, 20, stdin))
    {
        int in[3] = {}, t = 0;
        for (int i = 0; str[i] != '\n'; ++i)
        {
            if (str[i] == ' ')
                ++t;
            else
                in[t] = in[t] * 10 + str[i] - '0';
        }

        long long sum = 0;
        int low_b = 0, up_b = -1;
        if (!t)
            up_b = in[0];
        else if (t == 1)
            up_b = MIN(in[1], in[0]); //N 元最多用 N 個錢幣
        else if (t == 2)
        {
            low_b = in[1];
            up_b = MIN(in[2], in[0]);
        }

        for (int i = low_b; i <= up_b; ++i)
            sum += DP[in[0]][i];

        printf("%lld\n", sum);
    }

    return 0;
}