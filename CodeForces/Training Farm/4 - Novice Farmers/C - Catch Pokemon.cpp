#include<cstdio>
typedef long long LL;

int main()
{
    int N, C, W, B;
    static int d[1000005] = {};
    scanf("%d%d%d%d", &N, &C, &W, &B);

    int dis;
    for (int i = 1; i <= N; i++)
        scanf("%d", &d[i]);

    for (int i = N; i > 1; i--)
        d[i] = d[i] - d[i - 1];
    d[1] = 0;

    int ans = 0;

    if (C <= B)
    {
        int  start = 1, count = 1;
        LL use = C;
        ans = 1;

        for (int i = 2; i <= N; i++)
        {
            use += (LL)W*d[i] + C;
            while (use > B)
            {
                start++;
                use -= (LL)(W*d[start] + C);//¦©±¼°_©lªº
                count--;

                if (start == i)
                    break;
            }

            count++;

            if (count > ans)
                ans = count;
        }

    }

    printf("%d\n", ans);

    return 0;
}