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

            if (now > H)//�j�󤫤~�⪦�X�h
            {
                isSucceed = true;
                break;
            }

            now -= D;

            if (now < 0)//�p��0�~�⥢��
            {
                isSucceed = false;
                break;
            }
        }
        printf("%s on day %d\n", isSucceed ? "success" : "failure", day);
    }
    return 0;
}