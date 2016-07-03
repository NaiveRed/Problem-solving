#include<cstdio>
#define N 100

int main()
{
    bool student[N];
    int ans[N] = {};
    int i;

    for (int k = 1; k <= 1000; k++)
    {
        for (i = 0; i < N; i++)
            student[i] = true;
        int now = 0;

        for (i = 1; i < N; i++)//¶]99¦¸
        {
            int count = k;

            while (count)
            {
                count--;
                if (!count)
                    student[now] = false;

                if (i & 1)
                    do
                    {
                    now++;
                    if (now == N)
                        now = 0;
                    } while (!student[now]);
                else
                    do
                    {
                    now--;
                    if (now < 0)
                        now = N - 1;
                    } while (!student[now]);
            }
        }

        for (i = 0; i < N; i++)
            if (student[i])
            {
            if (!ans[i])
                ans[i] = k;
            break;
            }
    }

    int m;
    while (scanf("%d", &m) && m)
        printf("%d\n", ans[m - 1]);

    return 0;
}