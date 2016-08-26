#include<cstdio>
#include<cstring>

int main()
{
    char str[16];
    int Case = 1;
    while (fgets(str, 16, stdin) && str[0] != '#')
    {
        printf("Case %d: ", Case++);
        if (!strcmp(str, "HELLO\n"))
            puts("ENGLISH");
        else if (!strcmp(str, "HOLA\n"))
            puts("SPANISH");
        else if (!strcmp(str, "HALLO\n"))
            puts("GERMAN");
        else if (!strcmp(str, "BONJOUR\n"))
            puts("FRENCH");
        else if (!strcmp(str, "CIAO\n"))
            puts("ITALIAN");
        else if (!strcmp(str, "ZDRAVSTVUJTE\n"))
            puts("RUSSIAN");
        else
            puts("UNKNOWN");
    }

    return 0;
}