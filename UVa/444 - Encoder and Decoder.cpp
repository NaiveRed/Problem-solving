#include <cstdio>
#include <cstring>

int main()
{
    char str[245]; //80*3
    while (fgets(str, 245, stdin))
    {
        int len = strlen(str);
        str[--len] = '\0';

        if (str[0] >= '0' && str[0] <= '9')
        {
            int c = 0;
            for (int i = len - 1; i >= 0; --i)
            {
                c = c * 10 + str[i] - '0';

                if (c > 12) //deal with 100~122
                {
                    putchar(c);
                    c = 0;
                }
            }
        }
        else if (len)
        {
            for (int i = len - 1; i >= 0; --i)
            {
                int n = str[i];
                while (n)
                {
                    putchar((n % 10) + '0');
                    n /= 10;
                }
            }
        }

        putchar('\n');
    }

    return 0;
}