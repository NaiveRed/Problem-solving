#include<cstdio>
#define isOk(x,y) (x&&y&&x<=5&&y<=5)

inline void swap(char& obj, char& tar)
{
    char temp = obj;
    obj = tar;
    tar = temp;
}
int main()
{
    char puzzle[7][7], c;
    int Case = 0;
    while ((c = getchar()) != 'Z')
    {
        int i, j, raw, col;
        puzzle[1][1] = c;
        if (c == ' ')
            col = raw = 1;
        for (j = 2; j <= 5; j++)
            if ((puzzle[1][j] = getchar()) == ' ')
                raw = 1, col = j;
        getchar();
        for (i = 2; i <= 5; i++)
        {
            for (j = 1; j <= 5; j++)
                if ((puzzle[i][j] = getchar()) == ' ')
                    raw = i, col = j;
            getchar();
        }

        bool flag = true;
        while ((c = getchar()) != '0')
        {
            if (!flag || c == '\n')
                continue;

            if (c == 'A')//上面移下來
            {
                if (isOk(raw - 1, col))
                {
                    swap(puzzle[raw][col], puzzle[raw - 1][col]);
                    raw = raw - 1;
                }
                else
                    flag = false;
            }
            else if (c == 'B')//下面移上去
            {
                if (isOk(raw + 1, col))
                {
                    swap(puzzle[raw][col], puzzle[raw + 1][col]);
                    raw = raw + 1;
                }
                else
                    flag = false;
            }
            else if (c == 'R')//右邊往左移
            {
                if (isOk(raw, col + 1))
                {
                    swap(puzzle[raw][col], puzzle[raw][col + 1]);
                    col = col + 1;
                }
                else
                    flag = false;
            }
            else if (c == 'L')//左邊往右移
            {
                if (isOk(raw, col - 1))
                {
                    swap(puzzle[raw][col], puzzle[raw][col - 1]);
                    col = col - 1;
                }
                else
                    flag = false;
            }
        }
        getchar();

        if (Case)
            putchar('\n');

        printf("Puzzle #%d:\n", ++Case);
        if (!flag)
            puts("This puzzle has no final configuration.");
        else
        {
            for (i = 1; i <= 5; i++)
            {
                for (j = 1; j < 5; j++)
                {
                    putchar(puzzle[i][j]);
                    putchar(' ');
                }
                putchar(puzzle[i][5]);
                putchar('\n');
            }
        }
    }

    return 0;
}