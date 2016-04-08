#include<cstdio>
#include<stack>
#define N 30

struct Coin
{
    int d, v;
}coin[N];

int main()
{
    bool first = true;
    int t, w;
    while (scanf("%d%d", &t, &w) != EOF)
    {
        if (first)
            first = false;
        else
            putchar('\n');

        int n, i, j;
        scanf("%d", &n);
        for (i = 0; i < n; i++)
            scanf("%d%d", &coin[i].d, &coin[i].v);

        int dp[1001] = {};
        bool get[N][1001] = {};
        for (i = 0; i < n; i++)
        {
            int need = coin[i].d * 3 * w;//下潛與上浮的時間
            for (j = t; j >= need; j--)
                if (dp[j] < dp[j - need] + coin[i].v)
                {
                dp[j] = dp[j - need] + coin[i].v;
                get[i][j] = true;
                }
        }

        //照輸入順序輸出
        std::stack<int> s;
        for (i = n - 1, j = t; i >= 0; i--)
            if (get[i][j])
            {
            s.push(i);
            j -= coin[i].d * 3 * w;
            }

        printf("%d\n%d\n", dp[t], s.size());
        while (!s.empty())
        {
            i = s.top(), s.pop();
            printf("%d %d\n", coin[i].d, coin[i].v);
        }
    }

    return 0;
}