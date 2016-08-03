#include<cstdio>

int main()
{
    int Case;
    scanf("%d", &Case);

    while (Case--)
    {
        int num[3], ans[8] = {}, d, i, j;
        scanf("%d%d%d%d", &num[0], &num[1], &num[2], &d);
        if (d == 1)
            printf("%d %d %d\n", num[0], num[1], num[2]);
        else
        {
            for (i = 0; i < 3; i++)
                for (j = 0; j < 3; j++)
                    ans[i + j] += num[i] * num[j];

            if (d == 2)
            {
                printf("%d", ans[0]);
                for (i = 1; i < 5; i++)
                    printf(" %d", ans[i]);
                putchar('\n');
            }
            else
            {
                int ans3[7] = {};
                for (i = 0; i < 5; i++)
                    for (j = 0; j < 3; j++)
                        ans3[i + j] += ans[i] * num[j];

                printf("%d", ans3[0]);
                for (i = 1; i < 7; i++)
                    printf(" %d", ans3[i]);
                putchar('\n');
            }
        }
    }

    return 0;
}