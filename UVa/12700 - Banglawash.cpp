#include<cstdio>

int main()
{
    int Case;
    scanf("%d", &Case);
    for (int c = 1; c <= Case; c++)
    {
        int n, B = 0, W = 0, T = 0, A = 0;
        scanf("%d", &n);
        getchar();
        for (int i = 0; i < n; i++)
        {
            char c = getchar();
            if (c == 'B')
                B++;
            else if (c == 'W')
                W++;
            else if (c == 'T')
                T++;
            else if (c == 'A')
                A++;
        }
        getchar();

        printf("Case %d: ", c);
        if (A == n)
            puts("ABANDONED");
        else if (B == n - A)
            puts("BANGLAWASH");
        else if (W == n - A)
            puts("WHITEWASH");
        else if (B == W)
            printf("DRAW %d %d\n", B, T);
        else if (B > W)
            printf("BANGLADESH %d - %d\n", B, W);
        else
            printf("WWW %d - %d\n", W, B);
    }

    return 0;
}