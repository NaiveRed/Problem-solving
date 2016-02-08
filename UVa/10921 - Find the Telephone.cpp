#include<cstdio>

int main()
{
    char map[27] = "22233344455566677778889999" ;
    char c;
    while ((c = getchar()) != EOF)
    {
        if (c == '\n')
            putchar('\n');
        else if (c == '-' || c == '1' || c == '0')
            putchar(c);
        else 
            putchar(map[c - 'A']);
    }

    return 0;
}