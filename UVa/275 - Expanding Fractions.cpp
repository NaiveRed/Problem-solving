#include<cstdio>

int main()
{
    int n, m;
    int order[1000];

    while (scanf("%d%d", &n, &m) && m)
    {
        int count = 1;
        int remain[1000] = {};//餘數出現的順序

        while (n)
        {
            remain[n] = count;
            order[count++] = (n * 10) / m;//商

            n = (n * 10) % m;//餘數

            if (remain[n])
                break;
        }

        int i;

        putchar('.');
        for (i = 1; i < count; i++)
        {
            if (!(i % 50))
                putchar('\n');
            printf("%d", order[i]);
        }
        putchar('\n');

        if (!n)
            puts("This expansion terminates.\n");
        else
            printf("The last %d digits repeat forever.\n\n", count - remain[n]);
    }

    return 0;
}