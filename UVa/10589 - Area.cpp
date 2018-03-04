#include <cstdio>

inline double get_dis_square(double x1, double y1, double x2, double y2)
{
    return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}
int main()
{
    int N, a;

    while (scanf("%d%d", &N, &a) && N)
    {
        double M = 0;
        double x, y, aa = a * a;
        for (int i = 0; i < N; i++)
        {
            scanf("%lf%lf", &x, &y);
            //從四個頂點畫四分之一圓，所以只要點到四個頂點的距離都小於等於 a 就在該斜線範圍內
            if (get_dis_square(x, y, 0, a) <= aa && get_dis_square(x, y, a, 0) <= aa && get_dis_square(x, y, a, a) <= aa && get_dis_square(x, y, 0, 0) <= aa)
                M++;
        }

        printf("%.5lf\n", (M / N) * aa);
    }

    return 0;
}