//LIS: O(n^2)
#include <cstdio>
#include <cstring>
#define MAX(a, b) ((a) > (b) ? (a) : (b))

int main()
{
    int Case, train[4000], len[4000];
    scanf("%d", &Case);
    while (Case--)
    {
        int n;
        scanf("%d", &n);
        /* 1 2 3 4 要讓每個數字能選擇放在當前的前面或後面
        => 4 3 2 1 1 2 3 4 (e.g. 2 可以在 1 前面或後面)
        */
        for (int i = 0; i < n; ++i)
        {
            scanf("%d", &train[i + n]);
            train[n - i - 1] = train[i + n];
        }

        n <<= 1;
        int ans = 0;

        for (int i = 0; i < n; ++i)
        {
            len[i] = 1;
            for (int j = 0; j < i; ++j)
            {
                if (train[i] > train[j])
                    len[i] = MAX(len[i], len[j] + 1);
            }
            ans = MAX(ans, len[i]);
        }

        printf("%d\n", ans);
    }

    return 0;
}