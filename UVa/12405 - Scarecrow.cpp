#include<cstdio>

int main()
{
    int Case;
    scanf("%d", &Case);

    for (int c = 1; c <= Case; c++)
    {
        int n, i, count = 0;
        char ch;
        scanf("%d", &n);
        getchar();
        
        for (i = 0; i < n; i++)
            if (getchar() == '.')
            {
            count++;
            i += 2;
            if (i < n)
            {
                getchar();
                getchar();
            }
            }

        getchar();

        printf("Case %d: %d\n", c, count);
    }

    return 0;
}