#include <cstdio>

int main()
{
    int T, a, b;

    scanf("%d", &T);
    while (T--)
    {
        scanf("%d %d", &a, &b);
        if (a > b)
            puts(">");
        else if (b > a)
            puts("<");
        else if (a == b)
            puts("=");
    }

    return 0;
}
