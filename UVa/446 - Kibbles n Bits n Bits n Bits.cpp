#include<cstdio>

int main()
{
    int n;
    scanf("%d", &n);
    while (n--)
    {
        int a, b, c, i;
        char op[3], bin1[13], bin2[13];
        scanf("%X%s%X", &a, op, &b);
        if (op[0] == '+')
            c = a + b;
        else
            c = a - b;

        for (i = 0; i < 13; i++)
        {
            bin1[i] = (a % 2) + '0';
            a /= 2;
        }

        for (i = 0; i < 13; i++)
        {
            bin2[i] = (b % 2) + '0';
            b /= 2;
        }
        
        for (i = 12; i >= 0; i--)
            putchar(bin1[i]);
        putchar(' ');
        putchar(op[0]);
        putchar(' ');
        for (i = 12; i >= 0; i--)
            putchar(bin2[i]);
        printf(" = %d\n", c);
    }

    return 0;
}