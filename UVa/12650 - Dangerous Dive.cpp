#include<cstdio>

int getNum();
int main()
{
    bool people[10001] = {};
    int n, r, i;

    while (scanf("%d%d", &n, &r) != EOF)
    {
        for (i = 0; i <= n; i++)
            people[i] = false;

        int temp;
        for (i = 0; i < r; i++)
        {
            scanf("%d", &temp);
            people[temp] = true;
        }

        bool first = true;
        for (i = 1; i <= n; i++)
        {
            if (!people[i])
            {
                if (first)
                    first = false;

                printf("%d ", i);//每個後面都有空格
            }
        }

        if (first)
            putchar('*');
        putchar('\n');
    }

    return 0;
}
int getNum()
{
    char c;
    int num = 0;
    while ((c = getchar()) != '\n')
        num = num * 10 + c - '0';

    return num;
}
