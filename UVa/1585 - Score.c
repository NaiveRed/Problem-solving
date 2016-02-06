#include<stdio.h>

int main()
{
    int Case;
    char str[81];
    scanf("%d", &Case);

    getchar();
    while (Case--)
    {
        gets(str);

        int i, count = 0, score = 0;
        for (i = 0; str[i]; i++)
            if (str[i] == 'O')
                score += (++count);
            else
                count = 0;

        printf("%d\n", score);
    }

    return 0;
}