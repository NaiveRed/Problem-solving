#include<cstdio>

int main()
{
    char puzzle[12][12] = {};
    int r, c, Case = 0, id[12][12];
    while (scanf("%d", &r) && r)
    {
        scanf("%d", &c);

        getchar();
        int i, j, count = 1;

        //border
        for (i = 0; i <= c + 1; i++)
            puzzle[r + 1][i] = NULL;
        for (i = 0; i <= r + 1; i++)
            puzzle[i][c + 1] = NULL;

        for (i = 1; i <= r; i++)
        {
            for (j = 1; j <= c; j++)
            {
                puzzle[i][j] = getchar();
                if (puzzle[i][j] != '*' && (!puzzle[i - 1][j] || puzzle[i - 1][j] == '*' || !puzzle[i][j - 1] || puzzle[i][j - 1] == '*'))
                    id[i][j] = count++;
            }
            getchar();
        }

        if (Case)
            putchar('\n');

        printf("puzzle #%d:\n", ++Case);
        
        //Across
        puts("Across");
        for (i = 1; i <= r; i++)
        {
            for (j = 1; j <= c; j++)
            {
                if (puzzle[i][j] != '*' && (puzzle[i][j - 1] == '*' || !puzzle[i][j - 1]))
                {
                    printf("%3d.", id[i][j]);
                    for (int k = j; puzzle[i][k] != '*'&&puzzle[i][k]; k++)
                        putchar(puzzle[i][k]);
                    putchar('\n');
                }
            }
        }

        //Down
        puts("Down");
        for (i = 1; i <= r; i++)
        {
            for (j = 1; j <= c; j++)
            {
                if (puzzle[i][j] != '*' && (puzzle[i - 1][j] == '*' || !puzzle[i - 1][j]))
                {
                    printf("%3d.", id[i][j]);
                    for (int k = i; puzzle[k][j] != '*'&&puzzle[k][j]; k++)
                        putchar(puzzle[k][j]);
                    putchar('\n');
                }
            }
        }
    }

    return 0;
}