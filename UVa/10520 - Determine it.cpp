#include <cstdio>
#include <algorithm>
#define N 20
typedef long long LL;

inline int get_num()
{
    int n = 0;
    char c = getchar();
    if (c == EOF)
        return EOF;
    while (c != '\n' && c != ' ' && c != EOF)
    {
        n = n * 10 + c - '0';
        c = getchar();
    }

    return n;
}
int main()
{
    LL a[N][N] = {};

    int n;
    while ((n = get_num()) != EOF)
    {
        a[n][1] = get_num();

        /*
        j = 1
        4 1 為例
        (4, 1) = 1
        (3, 1) = 2*(4, 1)
        (2, 1) = 2*(3, 1)
        (1, 1) = 2*(2, 1)
        */
        for (int i = n - 1; i; i--)
        {
            //printf("(%d, %d)\n", i, 1);
            a[i][1] = a[i + 1][1] << 1;
        }
        // i = n
        for (int j = 2; j <= n; j++)
        {
            //printf("(%d, %d)\n", n, j);
            a[n][j] = a[n][j - 1] << 1;
        }

        //i>=j
        for (int i = n - 1; i >= 1; i--)
            for (int j = 2; j <= i; j++)
            {
                LL s1 = -1, s2 = -1;
                for (int k = i + 1; k <= n; k++)
                {
                    //printf("max1: (%d, %d) + (%d, %d)\n", k, 1, k, j);
                    s1 = std::max(a[k][1] + a[k][j], s1);
                }
                for (int k = 1; k < j; k++)
                {
                    //printf("max2: (%d, %d) + (%d, %d)\n", i, k, n, k);
                    s2 = std::max(a[i][k] + a[n][k], s2);
                }
                //printf("--------\n(%d, %d)\n======\n", i, j);
                a[i][j] = s1 + s2;
                //printf("(%d , %d) = %lld\n", i, j, a[i][j]);
            }

        //j>i
        for (int i = n - 1; i; i--)
            for (int j = i + 1; j <= n; j++)
            {
                a[i][j] = 0;
                for (int k = i; k < j; k++)
                {
                    //printf("(%d, %d) + (%d, %d)\n", i, k, k+1, j);
                    a[i][j] = std::max(a[i][j], a[i][k] + a[k + 1][j]);
                }
                //printf("--------\n(%d, %d)\n======\n", i, j);
            }

        printf("%lld\n", a[1][n]);
    }

    return 0;
}