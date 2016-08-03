#include<cstdio>
#define N 1000001

int factorial[N];
void solve();
int main()
{
    int n;
    solve();
    while (scanf("%d", &n) != EOF)
        printf("%d\n", factorial[n]);

    return 0;
}
void solve()
{
    int i;
    for (i = 0; i < N; i++)
        factorial[i] = 1;
    factorial[1] = 0;

    for (i = 2; i < N; i++)
    {
        if (factorial[i] == 1)
        {
            for (int j = 2; i*j < N; j++)
                factorial[i*j] = factorial[i] + factorial[j];
        }
    }

    for (i = 2; i < N; i++)
        factorial[i] += factorial[i - 1];
}