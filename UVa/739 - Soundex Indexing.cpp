#include<cstdio>
#include<cstring>

inline int code(char c)
{
    if (c == 'B' || c == 'P' || c == 'F' || c == 'V')
        return 1;
    else if (c == 'C' || c == 'S' || c == 'K' || c == 'G' || c == 'J' || c == 'Q' || c == 'X' || c == 'Z')
        return 2;
    else if (c == 'D' || c == 'T')
        return 3;
    else if (c == 'L')
        return 4;
    else if (c == 'M' || c == 'N')
        return 5;
    else if (c == 'R')
        return 6;
    else return 0;
}
int main()
{
    char str[22];
    puts("         NAME                     SOUNDEX CODE");

    while (fgets(str, 22, stdin))
    {
        int count = 3, len = strlen(str) - 1, last = code(str[0]);
        str[len] = NULL;
        printf("         %-25s%c", str, str[0]);
        for (int i = 1; i < len&&count; i++)
        {
            int c = code(str[i]);
            if (c != last&&c)
            {
                putchar('0' + c);
                count--;
            }
            
            last = c;
        }

        while (count--)
            putchar('0');
        putchar('\n');
    }

    puts("                   END OF OUTPUT");

    return 0;
}