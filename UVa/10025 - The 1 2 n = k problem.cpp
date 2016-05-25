#include<cstdio>

int main()
{
    int Case;
    scanf("%d", &Case);
    while (Case--)
    {
        int n;
        scanf("%d", &n);
        int sum = 0, i;
        if (!n)
            puts("3");//-1-2+3
        else
        {
            if (n < 0)
                n *= -1;

            for (i = 0; sum < n; i++)
                sum += i;
            i--;
            while ((sum - n) & 1)//相差偶數就一定湊得出來
                sum += ++i;

            printf("%d\n", i);
        }

        if (Case)
            putchar('\n');
    }

    return 0;
}