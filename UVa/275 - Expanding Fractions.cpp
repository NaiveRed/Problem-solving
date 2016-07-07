#include<cstdio>

int main()
{
    int n, m;
    int order[1000];

    while (scanf("%d%d", &n, &m) && m)
    {
        int count = 1;
        int remain[1000] = {};//�l�ƥX�{������

        while (n)
        {
            remain[n] = count;
            order[count++] = (n * 10) / m;//��

            n = (n * 10) % m;//�l��

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