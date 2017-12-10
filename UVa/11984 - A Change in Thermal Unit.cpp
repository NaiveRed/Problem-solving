#include <cstdio>

/*
0C = 32F
10C = 50F

10-0:50-32 => 10:18 => 1:1.8
*/

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        float c, d;
        scanf("%f%f", &c, &d);
        printf("Case %d: %.2lf\n", i, c + d / 1.8);
    }

    return 0;
}