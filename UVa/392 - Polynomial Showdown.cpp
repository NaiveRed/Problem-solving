#include<cstdio>

int main()
{
    int coe;
    while (scanf("%d", &coe) != EOF)
    {
        bool flag = false;
        if (coe)
        {
            flag = true;
            if (coe > 1 || coe < -1)
                printf("%d", coe);
            if (coe == -1)
                putchar('-');

            printf("x^8");
        }

        for (int i = 7; i; i--)
        {
            scanf("%d", &coe);
            if (coe)
            {
                if (coe && !flag)
                {
                    flag = true;
                    if (coe > 1 || coe < -1)
                        printf("%d", coe);
                    if (coe == -1)
                        putchar('-');

                    if (i == 1)
                        putchar('x');
                    else
                        printf("x^%d", i);
                }
                else
                {
                    if (coe)
                    {
                        if (coe < 0)
                            printf(" - ");
                        else
                            printf(" + ");

                        if (coe > 1 || coe < -1)
                            printf("%d", coe < 0 ? -coe : coe);
                        if (i == 1)
                            putchar('x');
                        else
                            printf("x^%d", i);
                    }
                }
            }
        }

        scanf("%d", &coe);
        if (!flag)
            printf("%d", coe);
        else if (coe < 0)
            printf(" - %d", -coe);
        else if (coe)
            printf(" + %d", coe);

        putchar('\n');
    }

    return 0;
}