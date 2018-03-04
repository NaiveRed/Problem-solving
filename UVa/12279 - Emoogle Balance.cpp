#include <cstdio>

int main()
{
    int n, c = 1;
    while (scanf("%d", &n) && n)
    {
        int a, treat = 0;
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &a);
            if (!a)
                treat++;
        }

        printf("Case %d: %d\n", c++, n - treat * 2); //(n-treat)-treat
    }
    return 0;
}