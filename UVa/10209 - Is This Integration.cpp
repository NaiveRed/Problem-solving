//參考: http://minstrel-uva.blogspot.tw/2011/10/acm-10209.html
#include <cstdio>
#include <cmath>

int main()
{
    const double pi = acos(-1.0), sq = sqrt(3);
    double r;

    while (scanf("%lf", &r) != EOF)
    {
        double rr = r * r;
        double x = 2 * ((rr / 2) - (rr * pi / 12) - (rr / 4 * sq * 0.5)); //格子狀的
        double y = rr - (0.25 * rr * pi) - 2 * x;                         //點點狀的
        double z = rr - 4 * x - 4 * y;                                    //斜線的        
        printf("%.3lf %.3lf %.3lf\n", z, 4 * y, 4 * x);
    }

    return 0;
}