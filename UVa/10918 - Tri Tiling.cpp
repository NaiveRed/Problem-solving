#include<cstdio>

int main()
{
    int n, ans[32] = { 1, 2 };
    for (int i = 2; i < 31; i++)
    {
        ans[i] = ans[i - 1] + ans[i - 2];
        ans[++i] = 2 * ans[i - 1] + ans[i - 2];
    }

    while (scanf("%d", &n) && n != -1)
        printf("%d\n", n & 1 ? 0 : ans[n]);

    return 0;
}