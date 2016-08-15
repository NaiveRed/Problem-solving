#include<cstdio>

int main()
{
    int Case;
    scanf("%d", &Case);
    for (int c = 1; c <= Case; c++)
    {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        printf("Case %d: ", c);
        if ((x >= y&&x <= z) || (x >= z&&x <= y))
            printf("%d\n", x);
        else if ((y >= x&&y <= z) || (y >= z&&y <= x))
            printf("%d\n", y);
        else if ((z >= y&&z <= x) || (z >= x&&z <= y))
            printf("%d\n", z);
    }

    return 0;
}