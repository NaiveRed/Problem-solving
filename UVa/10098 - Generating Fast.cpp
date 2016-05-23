#include<cstdio>
#include<algorithm>
#include<cstring>
#define N 12
using namespace std;

bool used[N];
int len;
char now[N], str[N];
void backtracking(int n);
int main()
{
    int Case;
    scanf("%d", &Case);
    getchar();
    while (Case--)
    {
        gets(str);
        len = strlen(str);
        fill(used, used + len, false);
        sort(str, str + len);

        backtracking(0);
        putchar('\n');
    }

    return 0;
}
void backtracking(int n)
{
    int i;
    if (n == len)
    {
        now[n] = '\0';
        puts(now);
    }
    else
    {
        char last = '\0';
        for (i = 0; i < len; i++)
        {
            if (!used[i] && str[i] != last)
            {
                used[i] = true;
                now[n] = str[i];
                last = str[i];

                backtracking(n + 1);

                used[i] = false;
            }
        }
    }
}