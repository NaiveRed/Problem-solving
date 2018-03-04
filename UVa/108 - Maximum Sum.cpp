#include <cstdio>
#include <cstring>
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define N 100

int max1D(int arr[], int n)
{
    int sum = 0, max = -1e9;
    for (int i = 0; i < n; i++)
    {
        if (sum > 0)
            sum += arr[i];
        else
            sum = arr[i];

        /*wrong: e.g. 100 -200
        sum += arr[i];
        if (sum < 0)
            sum = arr[i];*/

        max = MAX(max, sum);
    }

    return max;
}
int main()
{
    int n, board[N][N];
    while (scanf("%d", &n) != EOF)
    {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                scanf("%d", &board[i][j]);

        int ans = -1e9, arr[N] = {};
        //以不同列當作起始
        for (int i = 0; i < n; i++)
        {
            //逐次增加列數
            for (int r = i; r < n; r++)
            {
                //將 2D 合成 1D
                for (int k = 0; k < n; k++)
                    arr[k] += board[r][k];

                ans = MAX(ans, max1D(arr, n));
            }

            memset(arr, 0, sizeof arr);
        }

        printf("%d\n", ans);
    }

    return 0;
}