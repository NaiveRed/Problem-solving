#include<cstdio>

bool H[10][10], V[10][10];
inline bool check(int r, int c, int size)//以左上角的點去判斷
{
    for (int i = c; i < c + size; i++)
        if (!H[r][i] || !H[r + size][i])
            return false;
    for (int i = r; i < r + size; i++)
        if (!V[c][i] || !V[c+size][i])
            return false;
    return true;
}
int main()
{
    int n, Case = 1;
    while (scanf("%d", &n) != EOF)
    {
        int i, j;
        for (i = 0; i <= n; i++)
            for (j = 0; j <= n; j++)
                V[i][j] = H[i][j] = false;

        int m, a, b;
        char c;
        scanf("%d", &m);
        while (m--)
        {
            getchar();
            scanf("%c%d%d", &c, &a, &b);
            if (c == 'H')
                H[a][b] = true;
            else
                V[a][b] = true;
        }

        int size[10] = {};
        for (i = 1; i <= n; i++)//size
        {
            for (j = 1; j + i <= n; j++)//r
                for (int k = 1; k + i <= n; k++)//c
                    if (check(j, k, i))
                        size[i]++;
        }

        if (Case > 1)
            puts("\n**********************************\n");

        bool flag = true;
        printf("Problem #%d\n\n", Case++);
        for (i = 1; i <= n; i++)
            if (size[i])
            {
                printf("%d square (s) of size %d\n", size[i], i);
                flag = false;
            }
        if (flag)
            puts("No completed squares can be found.");
    }

    return 0;
}