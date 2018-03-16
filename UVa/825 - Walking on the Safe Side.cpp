#include <cstdio>
#include <cstring>
#define M 105
#define S 200
long long int city[M][M];
inline void read(int r)
{
    static char str[S];
    fgets(str, S, stdin);
    int n = 0, i = 0;

    while (true)
    {
        while (str[i] == ' ')
            ++i;
        if (str[i] == '\n')
            break;

        while (str[i] >= '0' && str[i] <= '9')
        {
            n = n * 10 + str[i] - '0';
            ++i;
        }

        city[r][n] = -1; //危險的
        n = 0;
    }
}
int main()
{
    int T;
    city[0][1] = 1;
    scanf("%d", &T);
    while (T--)
    {
        int W, N, r, c;
        scanf("%d%d", &W, &N);
        for (int i = 0; i < W; ++i)
        {
            scanf("%d", &r);
            read(r);
        }

        for (r = 1; r <= W; ++r)
            for (c = 1; c <= N; ++c)
                if (!city[r][c])
                    city[r][c] = (city[r - 1][c] != -1 ? city[r - 1][c] : 0) +
                                 (city[r][c - 1] != -1 ? city[r][c - 1] : 0); //上面 + 左邊

        printf("%lld\n", (city[W][N] != -1) ? city[W][N] : 0);

        if (T)
            putchar('\n');

        //init
        for (int i = 1; i <= W; ++i)
            memset(city[i], 0, sizeof city[i]);
    }

    return 0;
}