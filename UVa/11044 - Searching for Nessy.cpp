#include<cstdio>

int main()
{
    int n, m, Case;
    scanf("%d", &Case);

    while (Case--)
    {
        scanf("%d%d", &n, &m);

        n = (n - 2) / 3 + (((n - 2) % 3) ? 1 : 0);
        m = (m - 2) / 3 + (((m - 2) % 3) ? 1 : 0);

        printf("%d\n", n*m);
    }

    return 0;
}