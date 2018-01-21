#include <cstdio>

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int n, sum = 1;
        scanf("%d", &n);        
        for (int i = 2; i < n; i++)
        {
            if (!(n % i))
                sum += i;
        }

        if (sum > n)
            puts("abundant");
        else if (sum <n)
            puts("deficient");
        else
            puts("perfect");
    }

    return 0;
}