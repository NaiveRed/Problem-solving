#include<cstdio>

int main()
{
    int n;
    while (scanf("%d", &n) && n)
    {
        int i, k;
        //1,3,7,13,21,...
        for (i = 0, k = 1; k <= n; k += 2 * i)
        {
            if (k == n)
            {
                printf("%d %d\n", i+1, i+1);
                break;
            }

            i++;
        }

        int x, y, diff;
        if (k != n)
        {
            x = y = i + 1;
            diff = k - n;
            if (i & 1)//3,13,...
            {
                if (diff <= i)
                    x -= diff;
                else
                {
                    diff -= i;
                    x = diff;
                    y--;
                }
            }
            else//7,21,...
            {
                if (diff <= i)
                    y -= diff;
                else
                {
                    diff -= i;
                    y = diff;
                    x--;
                }
            }

            printf("%d %d\n", x, y);
        }
    }

    return 0;
}