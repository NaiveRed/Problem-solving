#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>
#define N 105

bool used[N];
char ans[N];
void backtrack(char *str, int now, const int &len)
{
    if (now == len)
    {
        ans[len] = '\0';
        puts(ans);
        return;
    }

    char last = '\0'; //防止選一樣的
    for (int i = 0; i < len; i++)
    {
        if (!used[i] && str[i] != last)
        {
            used[i] = true;
            ans[now] = str[i];
            backtrack(str, now + 1, len);
            used[i] = false;
            last = str[i];
        }
    }
}
int main()
{
    int n;
    char str[N];
    scanf("%d ", &n);
    while (n--)
    {
        fgets(str, N, stdin);
        int len = strlen(str);
        if (str[len - 1] == '\n')
            str[--len] = '\0';

        std::sort(str, str + len,
                  [](const char &a, const char &b) -> bool {
                      char aa = tolower(a), bb = tolower(b);
                      if (aa != bb)       //字母不同
                          return aa < bb; //比順序
                      else                //字母一樣，但可能一個大寫
                          return a < b;   //大寫在前
                  });

        backtrack(str, 0, len);
    }

    return 0;
}