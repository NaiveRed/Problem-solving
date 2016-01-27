#include<cstdio>

int main()
{
    int Case;
    scanf("%d", &Case);

    while (Case--)
    {
        int n, m, B1 = 0, B2 = 0;
        scanf("%d", &n);
        m = n;

        //decimal
        while (n)
        {
            if (n % 2)
                B1++;
            n /= 2;
        }

        //hex
        int hex = 0;
        while (m)
        {
            hex = hex * 16 + m % 10;
            m /= 10;
        }
        while (hex)
        {
            if (hex % 2)
                B2++;
            hex /= 2;
        }

        printf("%d %d\n", B1, B2);
    }

    return 0;
}
