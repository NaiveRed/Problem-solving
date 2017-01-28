#include<cstdio>

int main()
{
    int n, t;
    char num[200002];

    scanf("%d%d%s", &n, &t, num);
    int point = 0, i;
    for (; num[point] != '.'; point++);
    for (i = point + 1; i < n; i++)//找第一個大於 4 的
        if (num[i] >= '5')
            break;

    if (i == n)
    {
        puts(num);
        return 0;
    }

    for (i--; i > point&&t; i--, t--)//四捨"五入"
    {
        if (num[i + 1] < '5')
            break;

        num[i]++;
    }

    int tar = i + 1;

    if (t&&i == point&&num[i + 1] > '4')
    {
        num[i - 1]++;
        tar -= 2;
    }

    //處理進位
    for (i = tar; i; i--)
    {
        if (num[i] > '9')
        {
            num[i] = '0';
            num[i - 1]++;
        }
        else break;
    }

    if (num[0] > '9')
    {
        putchar('1');
        num[0] = '0';
    }

    for (i = 0; i <= tar; i++)
        putchar(num[i]);

    return 0;
}