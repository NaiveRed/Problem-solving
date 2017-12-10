#include <cstdio>

int main()
{
    double cows, cars, shows;
    while (scanf("%lf%lf%lf", &cows, &cars, &shows) != EOF)
    {
        double all = cars + cows, now = all - shows - 1;
        printf("%.5lf\n", cars / (all * now) * (all - 1));        
    }

    return 0;
}