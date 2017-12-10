#include <cstdio>

int main()
{
    char str[6];
    int T = 0;
    while (scanf("%s", str) && str[0] != '*')
        printf("Case %d: Hajj-e-%s\n", ++T, str[0] == 'H' ? "Akbar" : "Asghar");

    return 0;
}