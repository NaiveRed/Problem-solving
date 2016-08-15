#include<cstdio>

struct Command
{
    char com[3];
    int count, x[10];
}command[500];
inline void simulate(int com, int& r, int& c)
{
    int i, j;
    for (i = 0; i < com; i++)
    {
        int temp = 0;
        if (command[i].com[0] == 'D'&&command[i].com[1] == 'R')
        {
            for (j = 0; j < command[i].count; j++)
                if (r == command[i].x[j])
                {
                    r = c = 0;
                    return;
                }
                else if (r > command[i].x[j])
                    temp++;
            r -= temp;
        }
        else if (command[i].com[0] == 'D'&&command[i].com[1] == 'C')
        {
            for (j = 0; j < command[i].count; j++)
                if (c == command[i].x[j])
                {
                    r = c = 0;
                    return;
                }
                else if (c > command[i].x[j])
                    temp++;
            c -= temp;
        }
        else if (command[i].com[0] == 'I'&&command[i].com[1] == 'R')
        {
            for (j = 0; j < command[i].count; j++)
                if (r >= command[i].x[j])
                    temp++;
            r += temp;
        }
        else if (command[i].com[0] == 'I'&&command[i].com[1] == 'C')
        {
            for (j = 0; j < command[i].count; j++)
                if (c >= command[i].x[j])
                    temp++;
            c += temp;
        }
        else if (r == command[i].x[0] && c == command[i].x[1])
            r = command[i].x[2], c = command[i].x[3];
        else if (r == command[i].x[2] && c == command[i].x[3])
            r = command[i].x[0], c = command[i].x[1];
    }

}
int main()
{
    int row, col, Case = 1;
    while (scanf("%d%d", &row, &col) && row)
    {
        int com, i;
        scanf("%d", &com);//command
        for (i = 0; i < com; i++)
        {
            scanf("%s%d", command[i].com, &command[i].count);

            if (command[i].com[0] == 'E')
            {
                command[i].x[0] = command[i].count;
                scanf("%d%d%d", &command[i].x[1], &command[i].x[2], &command[i].x[3]);
            }
            else
                for (int j = 0; j < command[i].count; j++)
                    scanf("%d", &command[i].x[j]);
        }

        if (Case != 1)
            putchar('\n');
        printf("Spreadsheet #%d\n", Case++);
        int r, c, query;
        scanf("%d", &query);//query
        for (i = 0; i < query; i++)
        {
            scanf("%d%d", &r, &c);
            int rr = r, cc = c;
            simulate(com, r, c);
            if (r)
                printf("Cell data in (%d,%d) moved to (%d,%d)\n", rr, cc, r, c);
            else
                printf("Cell data in (%d,%d) GONE\n", rr, cc);
        }
    }

    return 0;
}