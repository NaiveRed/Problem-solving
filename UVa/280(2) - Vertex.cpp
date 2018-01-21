#include <cstdio>

inline int input()
{
    int n = 0;
    char c;
    while ((c = getchar()) != ' ' && c != '\n')
        n = n * 10 + c - '0';
    return n;
}
int main()
{
    int vertex;
    while (scanf("%d", &vertex) != EOF && vertex)
    {
        getchar();

        bool adjM[101][101] = {};
        int u, v, k;
        while (u = input())
            while (v = input())
                adjM[u][v] = true;

        //floyd-warshall
        for (k = 1; k <= vertex; k++)
            for (u = 1; u <= vertex; u++)
                for (v = 1; v <= vertex; v++)
                    if (!adjM[u][v])
                        adjM[u][v] |= (adjM[u][k] & adjM[k][v]);

        int n = input();
        while (n--)
        {
            int begin = input();
            int count = 0, ans[100] = {};

            for (int i = 1; i <= vertex; i++)
                if (!adjM[begin][i])
                    ans[count++] = i;

            printf("%d", count);
            for (int i = 0; i < count; i++)
                printf(" %d", ans[i]);
            putchar('\n');            
        }
    }

    return 0;
}