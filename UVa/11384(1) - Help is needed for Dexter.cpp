#include<cstdio>

int main()
{
    int dp[30];
    int n = 0, i;
    for (i = 1; i <= 1000000000; i <<= 1)
        dp[n++] = i;

    while (scanf("%d", &n) != EOF)
    {
        for (i = 0; i<30; i++)
            if (dp[i] > n)
                break;

        printf("%d\n", i);
    }

    return 0;
}