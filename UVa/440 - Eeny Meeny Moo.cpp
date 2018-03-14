//Josephus problem
#include <cstdio>
#define N 150
#define M 600

int main()
{
    //freopen("test.out", "w", stdout);
    int last[N][M] = {};
    for (int n = 2; n < N; ++n)
        for (int k = 1; k < M; ++k)
            last[n][k] = (last[n - 1][k] + k) % n;

    int n;
    while (scanf("%d", &n) && n)
    {
        for (int i = 1; i <M; ++i)
            if (!last[n - 1][i]) //直接將第一個排除，並把 Ulm 當第一個(idx = 0)
            {
                printf("%d\n", i);
                break;
            }
    }

    return 0;
}