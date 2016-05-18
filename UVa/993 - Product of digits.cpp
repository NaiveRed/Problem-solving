//greedy
#include<stdio.h>

int main()
{
    int Case;
    scanf("%d", &Case);
    while (Case--)
    {
        int n;
        scanf("%d", &n);
        if (n == 1)
        {
            puts("1");
            continue;
        }

        int num[10] = { 0, 1 }, i, j;
        for (i = 9; n > 1 && i > 1; --i)
        {
            while (!(n%i))
            {
                ++num[i];
                n /= i;
            }
        }

        if (n != 1)
            puts("-1");
        else
        {
            for (i = 2; i < 10; i++)
                for (j = 0; j < num[i]; j++)
                    putchar('0' + i);
            putchar('\n');
        }
    }


    return 0;
}