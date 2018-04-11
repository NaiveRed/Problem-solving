#include <cstdio>

int main()
{
    int T, a, b, n;
    char str[15] = {};
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d%d", &a, &b, &n);
        getchar();
        while (a <= b)
        {
            int p = (a + b) >> 1;
            //guess
            printf("%d\n", p);
            fflush(stdout);

            fgets(str, 15, stdin);
            if (str[4] == 'S')
                a = p + 1;
            else if (str[4] == 'B')
                b = p - 1;
            else if (str[0] == 'C' || str[0] == 'W' || --n == 0)
                break;
        }
    }

    return 0;
}