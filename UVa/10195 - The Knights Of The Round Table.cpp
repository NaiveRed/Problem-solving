#include <cstdio>
#include <cmath>

int main()
{
    double a, b, c;
    while (scanf("%lf%lf%lf", &a, &b, &c) == 3)
    {
        if (!(a + b + c))
            puts("The radius of the round table is: 0.000");
        else
        {
            double s = (a + b + c) / 2, area = sqrt(s * (s - a) * (s - b) * (s - c)); //Heron' formula
            //r = area*2/(a+b+c)
            printf("The radius of the round table is: %.3lf\n", area / s);
        }
    }

    return 0;
}