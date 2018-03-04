/*
剛好是二進位表示的 ascii code
a = | oo  .  o| = 64+32+1 = 97
    |76543.210|
*/
#include <cstdio>

int main()
{
    //freopen("test.out", "w", stdout);
    char str[15];
    fgets(str, 15, stdin);
    while (fgets(str, 15, stdin) && str[0] != '_')
    {
        int ascii = 0;        
        for (int i = 9, shift = 1; i; i--)
        {
            if (str[i] == '.')
                continue;
            else if (str[i] == 'o')
                ascii |= shift;
            shift <<= 1;
        }

        putchar(ascii);
    }

    return 0;
}