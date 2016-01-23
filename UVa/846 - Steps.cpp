/*
1 + 2 + 3 + ... + n + n-1 + ... + 1 
= n(n+1)/2+(n-1)(1+n-1)/2
= n^2
*/
#include<cstdio>
#include<cmath>

int main()
{
    int Case;
    scanf("%d", &Case);

    while (Case--)
    {
        int x, y;
        scanf("%d%d", &x, &y);

        int len = y - x;
        int step = (int)sqrt(len);

        if (len)
        {
            if (step*step == len)
                step = 2 * step - 1;
            else if (step*step + step >= len)
                step *= 2;
            else//step*step + step < len
                step = step * 2 + 1;
        }
        else
            step = 0;

        printf("%d\n", step);
    }

    return 0;
}