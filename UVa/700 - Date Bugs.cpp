#include<cstdio>
#define N 20
#define Y 10000

int main()
{
    int n, i, y[N], d[N], Case = 1;

    while (scanf("%d", &n) && n)
    {
        int a, b, max = 0, year;
        for (i = 0; i < n; i++)
        {
            scanf("%d%d%d", &y[i], &a, &b);
            d[i] = b - a;
            if (y[max] < y[i])
                max = i;
        }

        for (year = y[max]; year < Y; year++)
        {
            for (i = 0; i < n; i++)
                if ((year - y[i]) % d[i])//y[i] + d[i] * x = year
                    break;
            if (i == n)
                break;
        }

        printf("Case #%d:\n", Case++);
        if (year < Y)
            printf("The actual year is %d.\n\n", year);
        else
            puts("Unknown bugs detected.\n");
    }

    return 0;
}