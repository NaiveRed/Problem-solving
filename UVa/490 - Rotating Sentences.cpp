#include<cstdio>
#include<cstring>

int main()
{
    char str[100][101] = {};
    int count = 0, maxLen = 0;

    while (gets(str[count]))
    {
        int len = strlen(str[count++]);
        maxLen = maxLen < len ? len : maxLen;
    }

    for (int i = 0; i < maxLen; i++)
    {
        for (int j = count - 1; j >= 0; j--)
            putchar(str[j][i] ? str[j][i] : ' ');
        putchar('\n');
    }
    return 0;
}