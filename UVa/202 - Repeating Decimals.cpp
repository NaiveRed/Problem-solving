#include<cstdio>

int main()
{
    int x, y;
    int remain[3000], order[3001] = {};
    while (scanf("%d%d", &x, &y) != EOF)
    {
        int n = x, count = 1, i;
        bool part = false;

        for (i = 0; i < y; i++)
            remain[i] = 0;

        n %= y;
        while (n&&!remain[n])
        {
            remain[n] = count;
            order[count++] = n * 10 / y;

            n = (n * 10) % y;
        }

        printf("%d/%d = %d", x, y, x / y);
        putchar('.');

        if (n)//無限小數
        {
            for (i = 1; i < remain[n]; i++)
                printf("%d", order[i]);
            putchar('(');
            int temp = 50;
            for (; i < count&&temp; i++, temp--)
                printf("%d", order[i]);
            printf("%s", i == count ? ")" : "...)");
        }
        else//有限小數
        {
            for (i = 1; i < count; i++)
                printf("%d", order[i]);
            printf("(0)");
        }

        printf("\n   %d = number of digits in repeating cycle\n\n", n ? (count - remain[n]) : 1);
    }

    return 0;
}