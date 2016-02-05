#include<cstdio>
#include<string>
#include<cstring>
#include<set>
#include<cctype>

using namespace std;
int main()
{

    char str[201], temp[201];
    set<string> dict;

    while (gets(str))
    {
        int len = strlen(str), j = 0;
        for (int i = 0; i < len; i++)
        {
            if (isalpha(str[i]))
                temp[j++] = tolower(str[i]);
            else if (j)
            {
                temp[j] = '\0';
                j = 0;
                dict.insert(string(temp));
            }
        }

        if (j)
        {
            temp[j] = '\0';
            dict.insert(string(temp));
        }
    }

    for (auto s : dict)
        puts(s.c_str());

    return 0;
}