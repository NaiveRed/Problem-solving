#include<cstdio>
#include<cmath>
#include<cstring>

inline int GCD(int a, int b)
{
    while (b)
    {
        int t = a%b;
        a = b;
        b = t;
    }

    return a;
}
inline int to_num(char* str)
{
    int n = 0;
    for (int i = 0; str[i]; i++)
        n = n * 10 + str[i] - '0';
    return n;
}
int main()
{
    int j, Case = 1;
    while (scanf("%d", &j) && j != -1)
    {
        char str[10];
        scanf("%*d.%s", str);

        int count = 0, n, temp, len = strlen(str), gcd;
        temp = n = to_num(str);

        int a, b;//¤À¤l,¤À¥À
        if (j)
        {
            while (temp)
            {
                count++;
                temp /= 10;
            }

            a = n - n / (int)pow(10, j);
            b = (int)pow(10, len) - (int)pow(10, len - j);
            gcd = GCD(a, b);
            printf("Case %d: %d/%d\n", Case++, a / gcd, b / gcd);
        }
        else
        {
            if (n)
            {
                a = n;
                b = pow(10, len);
                gcd = GCD(a, b);
                printf("Case %d: %d/%d\n", Case++, a / gcd, b / gcd);
            }
            else//0 0.0
                printf("Case %d: 0/1\n", Case++);
        }
    }

    return 0;
}