#include <cstdio>
#define MIN(a, b) ((a) < (b) ? (a) : (b))

int main()
{
    //freopen("test.out", "w", stdout);
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int m, n, ans;
        char c;
        getchar();
        scanf("%c%d%d", &c, &m, &n);
        if (c == 'r' || c == 'Q') //n 皇后在 n >=4 時有解 (除了 n = 1)
            ans = MIN(m, n);
        else if (c == 'k') //間隔放，參考 UVa 696
            ans = (m * n + 1) / 2;
        else
        {
            /*king
            o _ o
            _ _ _
            o _ o ...
            ...
            */
            ans = ((m + 1) / 2) * ((n + 1) / 2); //括號很重要
        }
        printf("%d\n", ans);
    }
    return 0;
}