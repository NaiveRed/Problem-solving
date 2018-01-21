#include <cstdio>
#include <cstring>
int main()
{
    int Case;
    scanf("%d", &Case);
    getchar();
    while (Case--)
    {
        char str[10000] = {}, ans = '+';
        fgets(str, 10000, stdin);
        int len = strlen(str) - 1;
        str[len] = NULL;

        if (str[len - 2] == '3' && str[len - 1] == '5')
            ans = '-';
        else if (str[0] == '1' && str[1] == '9' && str[2] == '0')
            ans = '?';
        else if (str[0] == '9' && str[len - 1] == '4')
            ans = '*';
        
        putchar(ans);
        putchar('\n');
    }

    return 0;
}