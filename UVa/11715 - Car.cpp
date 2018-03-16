/*
三大運動公式:
u + a*t = v
(u + v)t/2 = s
v*v = u*u + 2*a*s
*/
#include <cstdio>
#include <cmath>
int main()
{
    int c, T = 0;
    double u, v, t, a, s;
    while (scanf("%d", &c) && c)
    {
        double ans1, ans2;
        if (c == 1)
        {
            scanf("%lf%lf%lf", &u, &v, &t);
            ans1 = (u + v) * t / 2; //s
            ans2 = (v - u) / t;     //a
        }
        else if (c == 2)
        {
            scanf("%lf%lf%lf", &u, &v, &a);
            ans2 = (v - u) / a;        //t
            ans1 = (u + v) * ans2 / 2; //s
        }
        else if (c == 3)
        {
            scanf("%lf%lf%lf", &u, &a, &s);
            ans1 = sqrt(u * u + 2 * a * s); //v
            ans2 = (ans1 - u) / a;          //t
        }
        else
        {
            scanf("%lf%lf%lf", &v, &a, &s);
            ans1 = sqrt(v * v - 2 * a * s); //u
            ans2 = (v - ans1) / a;          //t
        }

        printf("Case %d: %.3f %.3f\n", ++T, ans1, ans2);
    }

    return 0;
}