#include <cstdio>
#include <cstring>
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define N 150

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
int max1D(int arr[], int range, int limit)
{
    int max = -1e9, sum = 0, now = 0;
    for (int i = 0; i < range; i++)
    {
        //不能取重複的元素(超過 n 個)
        if (now == limit)
        {
            int idx = i - now, local_max;
            //先移掉最前面的
            --now;
            sum -= arr[idx];

            //繼續移且記錄最大值(local_max)和其剩餘數量(now)
            local_max = sum;
            while (++idx < i)
            {
                sum -= arr[idx];

                if (sum > local_max)
                {
                    local_max = sum;
                    now = i - idx - 1;
                }
            }

            sum = local_max;
        }

        if (sum > 0)
        {
            sum += arr[i];
            now++;
        }
        else
        {
            sum = arr[i];
            now = 1;
        }

        max = MAX(max, sum);
    }

    return max;
}
int main()
{
    //freopen("test.out", "w", stdout);
    int Case, board[N][N] = {}, sum[N] = {};
    scanf("%d", &Case);
    while (Case--)
    {
        int n, new_n;
        scanf("%d ", &n);
        new_n = (n << 1) - 2; //複製盤面後的大小 n + n - 2

        /*
        使它能取上下相連、左右相連的範圍。
        複製從上到下、從左到右的範圍到對稱位置
        */
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                board[i][j] = board[i + n][j] = board[i][j + n] = board[i + n][j + n] = get_num();        

        if (n == 1)
        {
            printf("%d\n", board[0][0]);
            continue;
        }

        /*for (int i = 0; i < new_n; i++)
        {
            for (int j = 0; j < new_n; j++)
                printf("%3d ", board[i][j]);
            putchar('\n');
        }*/

        //max2D
        int max = -1e9;
        for (int i = 0; i < n; i++)
        {
            for (int r = i; r < i + n && r < new_n; r++)
            {
                for (int k = 0; k < new_n; k++)
                    sum[k] += board[r][k];

                max = MAX(max, max1D(sum, new_n, n));
            }

            memset(sum, 0, sizeof sum);
        }

        printf("%d\n", max);
    }

    return 0;
}