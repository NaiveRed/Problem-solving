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
            while ((sum - n) & 1)//�ۮt���ƴN�@�w��o�X��
                sum += ++i;

            printf("%d\n", i);
        }

        if (Case)
            putchar('\n');
    }

    return 0;
}