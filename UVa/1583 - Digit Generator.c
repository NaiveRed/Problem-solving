#include<stdio.h>
#define MAX 100001

int main()
{
    int ans[MAX] = { 0 }, i, j;

    for (i = MAX-1; i ; i--)
    {
        int digits_sum = 0;
        for (j = i; j; j /= 10)
            digits_sum += j % 10;

        if (digits_sum + i < MAX)
            ans[digits_sum + i] = i;
    }

    int Case;
    scanf("%d", &Case);

    while (Case--)
    {
        int n;
        scanf("%d", &n);
        printf("%d\n", ans[n]);
    }

    return 0;
}