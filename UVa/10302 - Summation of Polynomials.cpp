#include<cstdio>

int main()
{
    long long ans[50001] = {};
    for (int i = 1; i < 50001; i++)
        ans[i] = ans[i - 1] + (long long)i*i*i;
    int n;
    while (scanf("%d", &n) != EOF)
        printf("%lld\n", ans[n]);

    return 0;
}