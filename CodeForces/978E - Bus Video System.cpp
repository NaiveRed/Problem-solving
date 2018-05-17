#include <cstdio>

int main()
{
    int max = -2e9, min = 2e9;
    int n, w, i;
    scanf("%d%d", &n, &w);

    int sum = 0, tmp;
    for (i = 0; i < n; ++i)
    {
        scanf("%d", &tmp);
        sum += tmp;
        if (sum < min)
        {
            min = sum;
            if (min < -w)
                break;
        }
        if (sum > max)
        {
            max = sum;
            if (max > w)
                break;
        }
    }

    /*
    x + max <= w
    x <= w - max 
    x <= w

    x + min >= 0
    x >= -min
    min >= 0
    */
    max = (w < w - max) ? w : (w - max);
    min = min > 0 ? 0 : -min;
    if (i != n || max < min)
        puts("0");
    else
        printf("%d\n", max - min + 1);

    return 0;
}
