//參考 UVa 861
#include <cstdio>
#define N 31
#define M 60
typedef long long LL;

int main()
{
    //freopen("test.out", "w", stdout);
    LL black[N][M] = {}, white[N][M] = {};
    int row_b[N] = {0, 1, 1};    //0,1,1,3,3,5,5,7,7...
    int row_w[N] = {0, 0, 2, 2}; //0,0,2,2,4,4,6,6,8...

    for (int i = 3; i < N; i += 2)
        row_b[i] = row_b[i + 1] = row_b[i - 1] + 2;
    for (int i = 4; i <= 28; i += 2)
        row_w[i] = row_w[i + 1] = row_w[i - 1] + 2;
    row_w[30] = row_w[29] + 2;

    for (int i = 0; i < N; ++i)
        black[i][0] = 1;
    for (int i = 0; i < N; ++i)
        white[i][0] = 1;

    for (int i = 1; i < N; ++i)
        for (int k = 1; k < M; ++k)
            black[i][k] = black[i - 1][k] + black[i - 1][k - 1] * (row_b[i] - (k - 1));

    for (int i = 2; i < N; ++i)
        for (int k = 1; k < M; ++k)
            white[i][k] = white[i - 1][k] + white[i - 1][k - 1] * (row_w[i] - (k - 1));

    int n, k;
    while (scanf("%d%d", &n, &k) && (n || k))
    {
        if (k >= M) //30+30
        {
            puts("0");
            continue;
        }

        LL sum = 0;
        for (int i = 0; i <= k; ++i)
            sum += (black[n][i] * white[n][k - i]);

        printf("%lld\n", sum);
    }

    return 0;
}