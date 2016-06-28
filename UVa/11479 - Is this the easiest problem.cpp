#include<cstdio>

typedef long long LL;
inline void swap(LL &a, LL &b);
int main()
{
    int Case;
    scanf("%d", &Case);

    LL x, y, z;
    for (int c = 1; c <= Case; c++)
    {
        printf("Case %d: ", c);

        scanf("%lld%lld%lld", &x, &y, &z);
        if (y > x)
            swap(x, y);
        if (z > x)
            swap(x, z);
        if (z > y)
            swap(y, z);

        if (z <= 0 || x >= y + z)
            puts("Invalid");
        else if (x == y&&y == z)
            puts("Equilateral");
        else if (x == y || y == z)
            puts("Isosceles");
        else
            puts("Scalene");
    }

    return 0;
}
void swap(LL &a, LL &b)
{
    LL temp = a;
    a = b;
    b = temp;
}