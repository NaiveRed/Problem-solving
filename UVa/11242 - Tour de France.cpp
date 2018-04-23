#include <cstdio>
#include <algorithm>
#define N 10

int main()
{
    int f_n, r_n;
    int f[N] = {}, r[N] = {};
    double d[N * N] = {};
    while (scanf("%d%d", &f_n, &r_n) == 2)
    {
        for (int i = 0; i < f_n; ++i)
            scanf("%d", &f[i]); //front, m
        for (int i = 0; i < r_n; ++i)
            scanf("%d", &r[i]); //rear, n

        for (int i = 0; i < f_n; ++i)
            for (int j = 0; j < r_n; ++j)
                d[i * r_n + j] = (double)r[j] / f[i]; //d = n/m

        std::sort(d, d + f_n * r_n);

        double max = 0; //spread = d2/d1, d1 < d2

        for (int i = 0; i < f_n * r_n - 1; ++i)
            if (max < d[i + 1] / d[i])
                max = d[i + 1] / d[i];

        printf("%.2lf\n", max);
    }

    return 0;
}