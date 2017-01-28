#include<cstdio>

int main()
{
    int n;
    scanf("%d", &n);
    puts("2");//2 -> 4 (lev 1 to lev 2)
    for (int i = 2; i <= n; i++)
        printf("%I64d\n", (long long)i*(i + 1)*(i + 1) - (i - 1));//{[i(i + 1)]^2 - [(i-1)i]}/i

    return 0;
}