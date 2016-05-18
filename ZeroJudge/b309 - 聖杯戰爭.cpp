#include<cstdio>
#include<cstring>
#include<cctype>
#define N 10000001
char str[N];
int main()
{
    char *name[7] = { "Saber", "Lancer", "Archer", "Rider", "Caster", "Assassin", "Berserker" };
    int n[7] = {}, i;
    while (fgets(str, N, stdin))
    {
        int len = strlen(str);
        for (i = 0; i < len; i++)
        {
            if (isalpha(str[i]))
                n[(tolower(str[i]) - 'a') % 7]++;
        }
    }

    int max = 0;
    for (i = 0; i < 7; i++)
        if (max < n[i])
            max = n[i];

    for (i = 7; i >= 0; i--)
        if (n[i] == max)
        {
        puts(name[i]);
        break;
        }

    return 0;
}