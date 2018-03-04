#include <cstdio>
#define N 21

inline int input()
{
    char c;
    int n = 0;
    while ((c = getchar()) != '\n' && c != ' ')
        n = n * 10 + c - '0';
    return n;
}
int main()
{
    //freopen("test.out", "w", stdout);
    int n, Case = 1;
    int M[N][N] = {};

    while (scanf("%d", &n) != EOF)
    {
        getchar();
        int u = 1, v;

        for (int i = 1; i < N; ++i)
            for (int j = 1; j < N; ++j)
                M[i][j] = 100;

        for (int i = 1; i < N; ++i)
            M[i][i] = 0;

        while (true)
        {
            for (int i = 0; i < n; ++i)
            {
                v = input();
                M[u][v] = 1;
                M[v][u] = 1;
            }

            if (++u < N - 1)
                n = input();
            else
                break;
        }

        // Floyd_Warshall
        for (int k = 1; k < N; ++k)
            for (int i = 1; i < N; ++i)
                for (int j = 1; j < N; ++j)
                    if (M[i][k] + M[k][j] < M[i][j])
                        M[i][j] = M[i][k] + M[k][j];

        printf("Test Set #%d\n", Case++);
        scanf("%d ", &n);
        for (int i = 0; i < n; ++i)
        {
            u = input();
            v = input();
            printf("%2d to %2d:%2d\n", u, v, M[u][v]);
        }

        putchar('\n');
    }
}