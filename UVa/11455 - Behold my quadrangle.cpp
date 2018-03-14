/*
Square: all 4 sides are equal.
Rectangle: each 2 sides are equal.
Quadrangle: maximum of these lengths must be less than the sum of other 3.
Banana: if none of the above conditions is satisfied, then print "banana".

ref: http://www.algorithmist.com/index.php/UVa_11455
*/
#include <cstdio>

int main()
{
    int n, a, b, c, d;
    scanf("%d", &n);
    while (n--)
    {
        scanf("%d%d%d%d", &a, &b, &c, &d);

        if (a == b && b == c && c == d)
            puts("square");
        else if ((a == b && c == d) || (a == c && b == d) || (a == d && b == c))
            puts("rectangle");
        else if (a + b + c <= d || a + b + d <= c || a + c + d <= b || b + c + d <= a)
            puts("banana");
        else //最大的邊要小於其他三邊之和
            puts("quadrangle");
    }

    return 0;
}