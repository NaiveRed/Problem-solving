#include<stdio.h>
#include<math.h>

int main()
{
    int Case;
    scanf("%d", &Case);

    while (Case--)
    {
        int n, m;
        double p;

        scanf("%d%lf%d", &n, &p, &m);

        if (p == 1)
            puts(m == 1 ? "1.0000" : "0.0000");
        else if (!p)
            puts("0.0000");
        else
        {
            int i;
            double r = 1, a = p;

            a *= pow(1 - p, m - 1);
            r *= pow(1 - p, n);

            printf("%.4lf\n", a / (1 - r));//無窮等比級數公式
        }
    }

    return 0;
}