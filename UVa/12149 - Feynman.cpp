#include<cstdio>

int main()
{
    int square[101] = {}, ans[101] = {};

    for (int i = 0; i < 101; i++)
        square[i] = i*i;

    for (int i = 1; i < 101; i++)
        ans[i] = ans[i - 1] + square[i];
    int n;
    while (scanf("%d", &n) && n)
        printf("%d\n", ans[n]);

    return 0;
}