#include<cstdio>

int main()
{
    int Case, ans[100] = {};
    scanf("%d", &Case);
    while (Case--)
    {
        int n, i;
        scanf("%d", &n);
        int sum = 0, count = 0;
        //先直接放2,3,4,... ，不要超過 n
        while (true)
        {
            ans[count] = count + 2;
            if (sum + ans[count] <= n)
                sum += ans[count++];
            else break;
        }

        int diff = n - sum;
        for (i = count - 1; diff; diff--)
        {
            //相差的從後面依序加一(循環)，直到總合為 n
            ans[i]++;
            sum++;
            i--;
            if (i < 0)
                i = count - 1;
        }

        for (i = 0; i < count - 1; i++)
            printf("%d ", ans[i]);
        printf("%d\n", ans[i]);
        if (Case)
            putchar('\n');
    }

    return 0;
}