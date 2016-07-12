#include<cstdio>
#include<cmath>

inline double getDis(int x, int y)
{
    return sqrt(x*x + y*y);
}
int main()
{
    int n;
    bool first = true;
    while (scanf("%d", &n) != EOF)
    {
        int all = 0, part = 0;
        double r = n - 0.5;
        for (int x = 0; x < n; x++)
            for (int y = 0; y < n; y++)
            {
            double d1 = getDis(x, y), d2 = getDis(x + 1, y + 1);//¥ª¤U¨¤¡B¥k¤U¨¤
            if (d2 <= r)
                all++;
            else if (d1 < r)
                part++;
            }

        if (first)
            first = false;
        else putchar('\n');

        printf("In the case n = %d, %d cells contain segments of the circle.\n", n, part*4);
        printf("There are %d cells completely contained in the circle.\n", all*4);
    }

    return 0;
}