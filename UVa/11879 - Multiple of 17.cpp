#include<cstdio>

int main()
{
    char str[101];
    while (gets(str))
    {
        if (str[0] == '0')
            break;

        int mod = 0;
        for (int i = 0; str[i]; i++)
        {
            mod = mod * 10 + str[i] - '0';
            mod %= 17;
        }

        puts(mod ? "0" : "1");
    }

    return 0;
}