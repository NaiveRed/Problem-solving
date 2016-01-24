#include<stdio.h>
#include<math.h>
int main()
{
    int max = sqrt(100000);
    int i, j, square[400];

    for (i = 1; i <= max; i++)
        square[i] = i*i;

    int a, b;
    while (scanf("%d%d", &a, &b) && a&&b)
    {
        i = 0;
        if (a != 1)
            for (i = 1; i <= max; i++)
                if (square[i] >= a)
                {
            i--;
            break;
                }

        for (j = 1; j <= max; j++)
            if (square[j] > b)
            {
            j--;
            break;
            }

        if (j > max)
            j--;

        printf("%d\n", j - i);
    }
    return 0;
}
