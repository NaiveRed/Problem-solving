//C++11
#include<cstdio>
#include<map>
#include<string>

using std::string;
int main()
{
    std::map<string, string> dict;
    
    char str[21];
    while (gets(str))
    {
        if (!str[0])
            break;
        
        bool flag = true;
        int idx = 0;
        char key[11],val[11];
        for (char c : str)
        {
            if (c == ' ')
            {
                val[idx] = '\0';
                flag = false;
                idx = 0;
            }
            else if (flag)
                val[idx++] = c;
            else
                key[idx++] = c;
        }
        key[idx] = '\0';
        dict[string(key)] = string(val);
    }
        
    while (gets(str))
    {
        string s(str);
        if (!dict[s].size())
            puts("eh");
        else
            puts(dict[s].c_str());
    }
        return 0;
}