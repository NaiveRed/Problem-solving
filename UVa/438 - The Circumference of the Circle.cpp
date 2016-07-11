#include<cstdio>
#include<cmath>

inline double getDis(double x1, double y1, double x2, double y2)
{
    return sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
}
int main()
{
    double x1, y1, x2, y2, x3, y3, pi = acos(-1);
    while (scanf("%lf%lf%lf%lf%lf%lf", &x1, &y1, &x2, &y2, &x3, &y3) != EOF)
    {
        double a = getDis(x1, y1, x2, y2), b = getDis(x1, y1, x3, y3), c = getDis(x3, y3, x2, y2);
        double cosA = (b*b + c*c - a*a) /( 2 * b*c);//餘弦定理
        double A = acos(cosA);
        double R2 = a / sin(A);//正弦定理

        printf("%.2lf\n", R2*pi);
    }

    return 0;
}