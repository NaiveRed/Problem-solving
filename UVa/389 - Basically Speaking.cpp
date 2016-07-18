#include<cstdio>
#include<cstring>

inline int charToNum(char c)
{
    if (c == 'A')
        return 10;
    else if (c == 'B')
        return 11;
    else if (c == 'C')
        return 12;
    else if (c == 'D')
        return 13;
    else if (c == 'E')
        return 14;
    else if (c == 'F')
        return 15;
    else
        return c - '0';
}
inline int getNum(char *str, int base)
{
    int num = 0, exp = 1, len = strlen(str);
    for (int i = len - 1; i >= 0; i--)
    {
        num += charToNum(str[i])*exp;
        exp *= base;
    }

    return num;
}
inline void print(int num, int base)
{
    //0
    if (!num)
    {
        puts("      0");
        return;
    }

    char str[7] = {};
    int i = 0;
    while (num)//短除法
    {
        if (i == 7)
            break;

        int temp = num % base;
        num /= base;
        if (temp < 10)
            str[i] = temp + '0';
        else if (temp == 10)
            str[i] = 'A';
        else if (temp == 11)
            str[i] = 'B';
        else if (temp == 12)
            str[i] = 'C';
        else if (temp == 13)
            str[i] = 'D';
        else if (temp == 14)
            str[i] = 'E';
        else if (temp == 15)
            str[i] = 'F';
        i++;
    }

    if (num)
        puts("  ERROR");
    else
    {
        for (int i = 6; i >= 0; i--)
            if (str[i])
                putchar(str[i]);
            else
                putchar(' ');
        putchar('\n');
    }
}
int main()
{
    char temp[8], str[8];
    int base, tar, i,j;
    while (scanf("%s%d%d", temp, &base, &tar) != EOF)
    {
        //處理前面無意義的零
        for (i = 0; temp[i]; i++)
            if (temp[i] != '0')
                break;
        for (j = 0; temp[i]; i++, j++)
            str[j] = temp[i];
        str[j] = NULL;

        int num = getNum(str, base);
        print(num, tar);
    }

    return 0;
}