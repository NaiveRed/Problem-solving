#include <cstdio>
#include <cstring>
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define N 75

inline int get_num()
{
    char c = getchar();
    int n = 0;
    bool flag = c == '-';

    if (flag)
        c = getchar();

    while (c >= '0' && c <= '9')
    {
        n = n * 10 + c - '0';
        c = getchar();
    }

    return flag ? -n : n;
}
int max1D(int arr[], int range)//Kadane's algo.
{
    int max = -1e9, sum1 = 0; //找連續最大的
    int min = 1e9, sum2 = 0;  //找連續最小的，用來求循環最大的(跨越中間的)
    int tot = 0;
    for (int i = 0; i < range; i++)
    {
        tot += arr[i];

        if (sum1 > 0)
            sum1 += arr[i];
        else
            sum1 = arr[i];

        max = MAX(max, sum1);

        if (sum2 < 0)
            sum2 += arr[i];
        else
            sum2 = arr[i];

        min = MIN(min, sum2);
    }

    return MAX(max, tot - min); //(連續最大的, 跨越中間最大的)
}
int main()
{
    //freopen("test.out", "w", stdout);
    int Case, board[N * 2][N] = {}, sum[N] = {};
    scanf("%d", &Case);
    while (Case--)
    {
        int n, new_n;
        scanf("%d ", &n);
        new_n = (n << 1) - 2; //複製盤面後的大小 n + n - 2

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                board[i][j] = board[i + n][j] = get_num();//只對稱到下方(row)

        if (n == 1)
        {
            printf("%d\n", board[0][0]);
            continue;
        }

        //max2D
        int max = -1e9;
        //窮舉起始列
        for (int i = 0; i < n; i++)
        {
            for (int r = i; r < i + n && r < new_n; r++) //逐次增加列數，最多取 n 個
            {
                //將 2D 合成 1D
                for (int k = 0; k < n; k++)
                    sum[k] += board[r][k];

                max = MAX(max, max1D(sum, n));
            }

            memset(sum, 0, sizeof sum);
        }

        printf("%d\n", max);
    }

    return 0;
}