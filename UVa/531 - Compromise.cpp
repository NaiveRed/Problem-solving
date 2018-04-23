#include <cstdio>
#include <cctype>
#include <string>
#include <stack>
#include <unordered_map>
using namespace std;

int main()
{
    //freopen("test.in","r",stdin);
    //freopen("test.out", "w", stdout);
    unordered_map<string, int> words;
    string id_to_word[205];
    char str[35], c;
    int len = 0, tot = 0;
    int idx1 = 1, idx2 = 1, sen1[101]{}, sen2[101]{};
    int lcs[101][101], path[101][101];
    while ((c = getchar()) != EOF)
    {
        do
        {
            if (isalpha(c))
                str[len++] = c;
            else if (len)
            {
                str[len] = '\0';
                string tmp(str);

                if (words.count(tmp))
                    sen1[idx1++] = words[tmp];
                else
                {
                    sen1[idx1++] = words[tmp] = ++tot;
                    id_to_word[tot] = tmp;
                }
                len = 0;
            }

        } while ((c = getchar()) != '#');
        getchar();

        while ((c = getchar()) != '#')
        {
            if (isalpha(c))
                str[len++] = c;
            else if (len)
            {
                str[len] = '\0';
                string tmp(str);

                if (words.count(tmp))
                    sen2[idx2++] = words[tmp];
                else
                {
                    sen2[idx2++] = words[tmp] = ++tot;
                    id_to_word[tot] = tmp;
                }
                len = 0;
            }
        }
        getchar();

        for (int i = 1; i < idx1; ++i)
            for (int j = 1; j < idx2; ++j)
            {
                if (sen1[i] == sen2[j])
                {
                    lcs[i][j] = lcs[i - 1][j - 1] + 1;
                    path[i][j] = 0; //0: 左斜
                }
                else
                {
                    lcs[i][j] = (lcs[i - 1][j] > lcs[i][j - 1]) ? lcs[i - 1][j] : lcs[i][j - 1];
                    path[i][j] = (lcs[i - 1][j] > lcs[i][j - 1]) ? 1 : 2; //1: 往上, 2: 往左
                }
            }

        stack<int> s;
        int i = idx1 - 1, j = idx2 - 1;
        while (i && j)
        {
            if (path[i][j] == 1)
                --i;
            else if (path[i][j] == 2)
                --j;
            else
            {
                s.push(sen1[i]);
                --i;
                --j;
            }
        }

        bool first = true;
        while (!s.empty())
        {
            if (!first)
                putchar(' ');
            else
                first = false;

            printf("%s", id_to_word[s.top()].c_str());
            s.pop();
        }
        putchar('\n');

        //init
        idx1 = idx2 = 1;
        len = tot = 0;
        words.clear();
    }

    return 0;
}