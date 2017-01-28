#include<cstdio>

int main()
{
    int n, c, i, time[100000];
    scanf("%d%d", &n, &c);
    for (i = 0; i < n; i++)
        scanf("%d", &time[i]);

    int count = 1;

    for (i = 1; i < n; i++)
    {
        if (time[i] - time[i - 1] <= c)
            count++;
        else
            count = 1;
    }

    printf("%d\n", count);

    return 0;
}