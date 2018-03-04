#include <cstdio>
#define N 4787

int main()
{
    static int fib[N][1005] = {{0}, {1}, {1}};

    int idx = 0;
    for (int i = 3; i < N; ++i)
    {
        for (int j = 0; j <= idx; ++j)
            fib[i][j] = fib[i - 1][j] + fib[i - 2][j];

        for (int j = 0; j <= idx; ++j)
            if (fib[i][j] > 9)
            {
                fib[i][j] -= 10;
                ++fib[i][j + 1];
                if (j == idx)
                {
                    ++idx;
                    break;
                }
            }

        /*if (idx == 1000)
            printf("%d\n", i);*/
    }

    int n;
    while (scanf("%d", &n) != EOF)
    {
        int i = idx;
        while (i >= 0 && !fib[n][i])
            --i;

        while (i >= 0)
            putchar('0' + fib[n][i--]);

        putchar('\n');
    }

    return 0;
}