#include<cstdio>
#include<string>
#include<cstring>
#include<map>
#include<cctype>
#include<algorithm>
#include<vector>

using namespace std;
string convert(string str);//字串轉小寫並排序
int main()
{
    map<string, int> Map;
    string words[1000];
    char str[81], temp[21];
    int i, k = 0;
    while (gets(str) && str[0] != '#')
    {
        int len = strlen(str), j = 0;
        for (i = 0; i < len; i++)
        {
            if (str[i] == ' ')
            {
                temp[j] = '\0';
                words[k] = string(temp);
                Map[convert(words[k])]++;
                k++;
                j = 0;
            }
            else
                temp[j++] = str[i];
        }

        if (j)
        {
            temp[j] = '\0';
            words[k] = string(temp);
            Map[convert(words[k])]++;
            k++;
        }

    }
   
    vector<string> v;
    for (auto s : words)
    {
        if (Map[convert(s)] == 1)
            v.push_back(s);
    }

    sort(v.begin(), v.end());

    for (auto s : v)
        puts(s.c_str());

    return 0;
}
string convert(string str)
{
    for (auto& c : str)
        c = tolower(c);

    sort(str.begin(), str.end());
    return str;
}