//https://amoshyc.github.io/ojsolution-build/uva/p10032.html#uva-10032-tug-of-war
#include <cstdio>
#include <cstring>
typedef unsigned long long ULL;
#define W 45001

inline int read()
{
    int n = 0;
    char ch;

    while ((ch = getchar()) >= '0' && ch <= '9')
        n = n * 10 + ch - '0';

    return n;
}
int main()
{
    //freopen("test.out", "w", stdout);
    ULL DP[W] = {};
    int w[100];
    int T;
    scanf("%d ", &T);
    while (T--)
    {
        int n, tot = 0;
        scanf("%d ", &n);
        for (int i = 0; i < n; ++i)
        {
            //scanf("%d", &w[i]);
            w[i] = read();
            tot += w[i];
        }

        /*
        DP[] = 
        b1: 0 人
        b1x: 1 人
        b1xx: 2 人
        ...
        DP[w]: b0110, w 的重量可用 2 或 1 人湊得
        */
        DP[0] = 1;
        for (int i = 0; i < n; ++i)
            for (int k = tot >> 1; k >= w[i]; --k)
                DP[k] |= (DP[k - w[i]] << 1); // k - w[i] 再加一人

        //( n >> 1 ): 一隊所需人數
        //總人數為奇數可再多一人
        //1 << (人數): 將人數轉成狀態
        ULL p = (ULL)1 << (n / 2);

        if (n & 1)
        {
            for (int k = tot >> 1; k >= 0; --k)
                if ((DP[k] & p) || (DP[k] & (p << 1)))
                {
                    printf("%d %d\n", k, tot - k);
                    break;
                }
        }
        else
        {
            for (int k = tot >> 1; k >= 0; --k)
                if (DP[k] & p)
                {
                    printf("%d %d\n", k, tot - k);
                    break;
                }
        }

        if (T)
            putchar('\n');

        memset(DP, 0, sizeof DP);
    }

    return 0;
}