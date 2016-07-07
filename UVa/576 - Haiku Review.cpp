#include<cstdio>
#include<cstring>

inline bool isVowel(char c)
{
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y');
}
int main()
{
    char str[201];
    while (gets(str) && strcmp(str, "e/o/i"))
    {
        int i, len = strlen(str);
        int need[3] = { 5, 7, 5 }, line = 0;
        bool flag = true;
        for (i = 0; i < len; i++)
        {
            if (str[i] == '/')
            {
                if (need[line] != 0)
                    break;
                line++;
                flag = true;
                continue;
            }
            else if (str[i] == ' ')
            {
                flag = true;
                continue;
            }

            if (isVowel(str[i]))
                if (flag)
                {
                need[line]--;
                flag = false;
                }

            if (!flag&&!isVowel(str[i]))
                flag = true;
        }

        if (i == len&&!need[2])
            puts("Y");
        else
            printf("%d\n", line + 1);
    }

    return 0;
}