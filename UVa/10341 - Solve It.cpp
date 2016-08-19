#include<cstdio>
#include<cmath>
#define EPS 1e-7

int p, q, r, s, t, u;
inline double F(double x)
{
    return p*exp(-x) + q*sin(x) + r*cos(x) + s*tan(x) + t*x*x + u;
}
int main()
{
    while (scanf("%d%d%d%d%d%d", &p, &q, &r, &s, &t, &u) != EOF)
    {
        double a = 0, b = 1, mid = 0.5;
        double Fmid, Fa = F(a), Fb = F(b);
        if (fabs(Fa) <= EPS)
            puts("0.0000");
        else if (fabs(Fb) <= EPS)
            puts("1.0000");
        else if (Fa*Fb < 0)
        {
            while (b - a >= EPS)
            {
                Fmid = F(mid);
                if (fabs(Fmid) <= EPS)
                    break;
                else if (Fmid < 0)
                    b = mid;
                else
                    a = mid;
                mid = (a + b) / 2;
            }

            printf("%.4lf\n", mid);
        }
        else
            puts("No solution");
    }

    return 0;
}