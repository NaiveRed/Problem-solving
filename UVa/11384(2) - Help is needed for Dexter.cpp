#include<cstdio>

int main()
{
    int n;
    while (scanf("%d", &n) != EOF)
    {
        int ans = 0;
        for (int i = 1; i <= n; i <<= 1,ans++);
        printf("%d\n", ans);
    }

    return 0;
}