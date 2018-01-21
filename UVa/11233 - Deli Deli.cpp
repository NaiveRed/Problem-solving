#include <cstdio>
#include <string>
#include <cstring>
#include <unordered_map>
using namespace std;

int main()
{
    char str[50];
    unordered_map<string, string> table;
    int L, N;
    scanf("%d%d", &L, &N);
    getchar();
    for (int i = 0; i < L; i++)
    {
        fgets(str, 50, stdin);
        str[strlen(str) - 1] = NULL;
        char *space = strchr(str, ' ');
        *space = NULL;

        table[string(str)] = string(space + 1);
    }

    for (int i = 0; i < N; i++)
    {
        fgets(str, 50, stdin);
        int len = strlen(str);
        str[--len] = NULL;
        string target(str);

        if (table.count(target))
            puts(table[target].c_str());
        else
        {
            if (str[len - 1] == 'y' && str[len - 2] != 'a' && str[len - 2] != 'e' && str[len - 2] != 'i' && str[len - 2] != 'o' && str[len - 2] != 'u')
            {
                str[len - 1] = NULL;
                strcat(str, "ies");
            }
            else if (str[len - 1] == 'o' || str[len - 1] == 's' || str[len - 1] == 'x' || (str[len - 1] == 'h' && str[len - 2] == 'c') || (str[len - 1] == 'h' && str[len - 2] == 's'))
                strcat(str, "es");
            else
                strcat(str + len, "s");
            puts(str);
        }
    }

    return 0;
}
