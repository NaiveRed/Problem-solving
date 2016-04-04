#include<cstdio>
#define MAX(a,b) ((a)>(b)?(a):(b))
#define N 101

inline int input();
int main()
{
    int C, S, Q, Case = 0;
    int d[N][N];

    while (C = input())
    {
        S = input();
        Q = input();

        int i, j, k;
        //init
        for (i = 0; i <= C; i++)
            for (j = 0; j <= C; j++)
                d[i][j] = 1e9;

        for (i = 0; i < S; i++)
        {
            int  c1, c2, decibel;
            c1 = input(), c2 = input(), decibel = input();
            d[c1][c2] = d[c2][c1] = decibel;
        }

        //Floyd-Warshall
        for (k = 1; k <= C; k++)
            for (i = 1; i <= C; i++)
                for (j = 1; j <= C; j++)
                {
            int max = MAX(d[i][k], d[k][j]);//取最大的分貝
            if (max < d[i][j])
                d[j][i] = d[i][j] = max;
                }

        if (Case)
            putchar('\n');
        printf("Case #%d\n", ++Case);

        for (int i = 0; i < Q; i++)
        {
            int c1, c2;
            c1 = input(), c2 = input();
            
            if (d[c1][c2] != 1e9)
                printf("%d\n", d[c1][c2]);
            else
                puts("no path");
        }
    }

    return 0;
}
int input()
{
    int n = 0;
    char c;
    while ((c = getchar()) != ' '&&c != '\n')
        n = n * 10 + c - '0';
    return n;
}