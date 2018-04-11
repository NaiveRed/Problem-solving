/*
N = 10M + k
X = N - M = 10M + k - M
M = (X - k) / 9
*/
#include <cstdio>
typedef long long LL;

int main()
{
    LL x;
    while (scanf("%lld", &x) && x)
    {
        bool first = true;
        for (int i = 9; i >= 0; --i)
            if ((x - i) % 9 == 0)
            {
                if (!first)
                    putchar(' ');
                printf("%lld", (LL)(x - i) / 9 * 10 + i);
                first = false;
            }
        putchar('\n');
    }

    return 0;
}