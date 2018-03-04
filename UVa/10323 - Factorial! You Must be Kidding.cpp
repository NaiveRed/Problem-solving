/*
參考: http://www.algorithmist.com/index.php/UVa_10323
n can be negative.
F(0) = 0 * F(-1)
從上式推得 F(-1) = F(0)/0 = INF (OVERFLOW)
從原式可得 F(-1) = -1 * F(-2)
又可得    F(-2) = -F(-1) = -INF (UNDERFLOW)
F(-2) = -2 * F(-3)
F(-3) = F(-2)/-2 = INF
以此類推下去
*/
#include <cstdio>
#define OVER 6227020800
#define UNDER 10000

int main()
{
    int overflow = 0, underflow = 0;
    long long factorial[20] = {1};
    for (int i = 1;; i++)
    {
        factorial[i] = factorial[i - 1] * i;
        if (factorial[i] > OVER)
        {
            overflow = i - 1;
            break;
        }
        else if (!underflow && factorial[i] > UNDER)
            underflow = i;
    }

    //printf("%d %d\n", overflow, underflow);
    int n;
    while (scanf("%d", &n) != EOF)
    {
        if (n < 0)
            puts(((-n) & 1) ? "Overflow!" : "Underflow!");
        else
        {
            if (n < underflow) //8
                puts("Underflow!");
            else if (n > overflow) //13
                puts("Overflow!");
            else
                printf("%lld\n", factorial[n]);
        }
    }
    return 0;
}