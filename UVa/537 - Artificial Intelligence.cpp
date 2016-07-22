#include<cstdio>

inline void countUnit(double& n, char unit)
{
    if (unit == 'm')
        n *= 0.001;
    else if (unit == 'k')
        n *= 1000;
    else if (unit == 'M')
        n *= 1000000;
}
int main()
{
    int n;
    scanf("%d\r", &n);
    for (int Case = 1; Case <= n; Case++)
    {
        double P = -1, U = -1, I = -1;
        char c;
        while ((c = getchar()) != '\n')
        {
            char unit;
            if (c == 'P')
            {
                if ((c = getchar()) == '=')
                {
                    scanf("%lf%c", &P, &unit);
                    countUnit(P, unit);
                }
            }
            else if (c == 'U')
            {
                if ((c = getchar()) == '=')
                {
                    scanf("%lf%c", &U, &unit);
                    countUnit(U, unit);
                }
            }
            else if (c == 'I')
            {
                if ((c = getchar()) == '=')
                {
                    scanf("%lf%c", &I, &unit);
                    countUnit(I, unit);
                }
            }
        }

        printf("Problem #%d\n", Case);
        if (U != -1 && I != -1)
            printf("P=%.02lfW\n\n", U*I);
        else if (P != -1 && I != -1)
            printf("U=%.02lfV\n\n", P / I);
        else if (U != -1 && P != -1)
            printf("I=%.02lfA\n\n", P / U);
    }

    return 0;
}