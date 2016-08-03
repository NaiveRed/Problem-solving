#include<cstdio>

int main()
{
    int Case;
    scanf("%d", &Case);
    while (Case--)
    {
        int n;
        scanf("%d", &n);
        int a = n*n;
        printf("%d %d\n", a, a*n);
    }

    return 0;
}