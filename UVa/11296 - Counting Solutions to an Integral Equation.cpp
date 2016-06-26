#include<cstdio>
#define N 1000001

long long ans[N];
int main()
{
    for (int i = 1; i < N; i++)
        ans[i] = ans[i - 1] + i;

    int n;
    while (scanf("%d", &n) != EOF)
        printf("%lld\n", ans[(n / 2) + 1]);

    return 0;
}