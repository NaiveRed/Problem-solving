#include <cstdio>
#include <cstring>
#include <cctype>
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define N 32

inline int get_num(int *d, int len, int base)
{
    int n = 0, e = 1;
    for (int i = len - 1; i >= 0; --i, e *= base)
        n += d[i] * e;
    return n;
}
int main()
{
    char n1[N], n2[N];

    while (scanf("%s%s", n1, n2) != EOF)
    {
        getchar();
        int len1 = strlen(n1), len2 = strlen(n2);
        int b1 = 0, b2 = 0, digits1[N], digits2[N];
        for (int i = 0; i < len1; ++i)
        {
            digits1[i] = n1[i] - (isdigit(n1[i]) ? '0' : ('A' - 10));
            b1 = MAX(digits1[i], b1);
        }
        for (int i = 0; i < len2; ++i)
        {
            digits2[i] = n2[i] - (isdigit(n2[i]) ? '0' : ('A' - 10));
            b2 = MAX(digits2[i], b2);
        }

        int tmp = MAX(2, b2 + 1);
        for (b1 = MAX(2, b1 + 1); b1 <= 36; ++b1)
        {
            for (b2 = tmp; b2 <= 36; ++b2)
                if (get_num(digits1, len1, b1) == get_num(digits2, len2, b2))
                {
                    printf("%s (base %d) = %s (base %d)\n", n1, b1, n2, b2);
                    break;
                }
            if (b2 <= 36)
                break;
        }

        if (b1 > 36)
            printf("%s is not equal to %s in any base 2..36\n", n1, n2);
    }

    return 0;
}