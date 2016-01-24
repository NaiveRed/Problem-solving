#include <stdio.h>
#include<math.h>
#define LL long long

int main(void)
{
    int n;
    LL day;
    while (scanf("%d%lld", &n, &day) != EOF)
    {
        LL test = (LL)sqrt(day);
        LL sum = test*((test + n - 1) + n) / 2;
        n = test + n - 1;

        if (sum > day)
        {
            while (sum >= day)
                sum -= (n--);
            n++;
        }
        else if (sum < day)
        {
            while (sum < day)
                sum += (++n);
        }

            printf("%d\n", n);
    }

    return 0;
}
