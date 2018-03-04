/*
1 9 18 18*9 18*9*2 ...
2~9 win (stan)
10~18 lose
19~18*9 win
18*9~18*9*2 lose
...
*/
#include <cstdio>

int main()
{
    unsigned int p, n;

    while (scanf("%u", &n) != EOF)
    {
        p = 1;
        bool stan = true;
        while (true)
        {
            p *= stan ? 9 : 2;
            if (n <= p)
                break;

            stan = !stan;
        }

        puts(stan ? "Stan wins." : "Ollie wins.");
    }

    return 0;
}