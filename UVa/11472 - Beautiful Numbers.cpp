#include <cstdio>
#include <cstring>
#define BASE 10
#define LEN 101
#define MASK 1024
#define MOD 1000000007

int read()
{
    int n = 0;
    char c;
    while ((c = getchar()) >= '0' && c <= '9')
        n = n * 10 + c - '0';
    return n;
}
int main()
{
    /*
    [len][last_digit][used_number(bitmask)]
    bitmask:
    0000 0000 01: 有使用 0
    0000 0000 10: 有使用 1
    0000 0001 00: 有使用 2
    */
    static int DP[LEN][BASE][MASK] = {};

    int T;
    scanf("%d ", &T);
    while (T--)
    {
        int n = read(), m = read();
        //scanf("%d%d", &n, &m);

        //初始長度為 1 的
        for (int i = 1; i < n; ++i) //no leading zero
            DP[1][i][1 << i] = 1;

        int all_used = (1 << n) - 1; //10000(binary), 減一即為所有數字皆使用(01111)

        for (int i = 2; i <= m; ++i)    //length
            for (int j = 0; j < n; ++j) //last digit
                for (int used = 1; used <= all_used; ++used)
                {
                    //j 後面可接 j +/- 1
                    if (j + 1 < n)
                    {
                        /*
                        [][][binary]
                        e.g.
                        j = 3
                        DP[i][4][11000] += DP[i-1][3][01000]
                        3 變成 34(j)(j+1)                        
                        */
                        int u1 = used | (1 << (j + 1));
                        DP[i][j + 1][u1] += DP[i - 1][j][used];
                        if (DP[i][j + 1][u1] >= MOD)
                            DP[i][j + 1][u1] %= MOD;
                    }

                    if (j)
                    {
                        //(j)(j-1)
                        int u2 = used | (1 << (j - 1));
                        DP[i][j - 1][u2] += DP[i - 1][j][used];
                        if (DP[i][j - 1][u2] >= MOD)
                            DP[i][j - 1][u2] %= MOD;
                    }
                }

        int sum = 0;

        //加總所有可能長度(i)的 beautiful number，結尾可為 0 ~ n-1
        for (int i = n; i <= m; ++i)
            for (int j = 0; j < n; ++j)
                sum = (sum + DP[i][j][all_used]) % MOD; //all_used: 0~ n-1 皆使用過

        printf("%d\n", sum);
        memset(DP, 0, sizeof DP);
    }

    return 0;
}