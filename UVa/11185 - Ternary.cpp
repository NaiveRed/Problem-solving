#include<cstdio>

int main()
{
    int n;
    while (scanf("%d", &n) && n >= 0)
    {
        if (!n)
        {
            puts("0");
            continue;
        }
        
        int ternary[20] = {0}, count = 0;
        while (n)
        {
            ternary[++count] = n % 3;
            n /= 3;
        }

        while (count)
            printf("%d", ternary[count--]);
        putchar('\n');
    }

    return 0;
}