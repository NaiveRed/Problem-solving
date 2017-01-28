#include<cstdio>

int main()
{
    int n,a,b;
    scanf("%d", &n);
    if (n == 1)
    {
        scanf("%d", &a);
        if (a == 15)
            puts("DOWN");
        else if (a == 0)
            puts("UP");
        else puts("-1");
    }
    else
    {        
        for (int i = 0; i < n - 2; i++)
            scanf("%*d");
        scanf("%d%d", &a,&b);
        if (a < b)
        {
            if (b == 15)
                puts("DOWN");
            else
                puts("UP");
        }
        else
        {
            if (b == 0)
                puts("UP");
            else
                puts("DOWN");
        }

    }

    return 0;
}