#include<stdio.h>
#include<stdbool.h>

int main()
{
    double H, U, D, F;

    while (scanf("%lf%lf%lf%lf", &H, &U, &D, &F) && H)
    {
        int day = 0;
        double now = 0, fatigue = U*F / 100;
        bool isSucceed;

        while (++day)
        {
            if (U > 0)
            {
                now += U;
                U -= fatigue;
            }

            if (now > H)//大於井才算爬出去
            {
                isSucceed = true;
                break;
            }

            now -= D;

            if (now < 0)//小於0才算失敗
            {
                isSucceed = false;
                break;
            }
        }
        printf("%s on day %d\n", isSucceed ? "success" : "failure", day);
    }
    return 0;
}