#include<cstdio>
#define N 10001

int main()
{
    //60 * 60 * 60 - 59 * 59 * 59 ¶W¹L10000¤F
    int x[N] = {}, y[N] = {}, n;
    bool isOk[N] = {};
    for (int i = 2; i < 60; i++)
    {
        int iii = i*i*i;
        for (int j = 1; j < i; j++)
        {
            n = iii - j*j*j;
            if (n <= 10000 && !isOk[n])
            {
                isOk[n] = true;
                x[n] = i;
                y[n] = j;
            }
        }
    }

    while (scanf("%d", &n) && n)
    {
        if (isOk[n])
            printf("%d %d\n", x[n], y[n]);
        else puts("No solution");
    }

    return 0;
}