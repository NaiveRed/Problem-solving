#include <cstdio>
#include <cmath>

int main()
{
    const double PI = atan(1.0) * 4;

    int n;
    double r; //r可不為整數
    while (scanf("%lf%d", &r, &n) != EOF)
    {
        //將每一塊小三角分成兩個直角三角形，計算單一塊的弧度後即可求出該塊面積
        double radian = PI / n; // 2PI/n/2
        // (r * cos(radian) * r * sin(radian) / 2) * 2 * n
        printf("%.3lf\n", r * cos(radian) * r * sin(radian) * n);
    }

    return 0;
}