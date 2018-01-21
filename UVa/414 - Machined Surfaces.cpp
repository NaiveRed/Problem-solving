#include <cstdio>
#define N 13
int main()
{
    int n;

    while (scanf("%d ", &n) == 1 && n)
    {
        int min = 25, count[N] = {}, total = 0;

        for (int i = 0; i < n; i++)
        {
            int space = 0;
            for (int j = 0; j < 25; j++)
                if (getchar() != 'X')
                    space++;
            count[i] = space;
            if (min > space)
                min = space;
            getchar();
        }

        for (int i = 0; i < n; i++)
            total += count[i] - min;

        printf("%d\n", total);
    }

    return 0;
}