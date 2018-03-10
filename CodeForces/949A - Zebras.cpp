#include <cstdio>
#include <vector>
#include <stack>
#define N 200005
using namespace std;

int main()
{
    char str[N];
    fgets(str + 1, N, stdin);
    vector<int> zero, one;
    int ans[N] = {}, ok = true;
    for (int i = 1; str[i] != '\n'; ++i)
    {
        if (str[i] == '0')
        {
            zero.push_back(i);
            if (!one.empty())
            {
                ans[i] = one.back();
                one.pop_back();
            }
        }
        else
        {
            if (zero.empty()) // can't find 0 before it(1)
            {
                ok = false;
                break;
            }
            else
            {
                one.push_back(i);
                ans[i] = zero.back();
                zero.pop_back();
            }
        }
    }

    if (ok && one.empty())
    {
        printf("%d\n", zero.size());
        for (int i : zero)
        {
            if (ans[i])
            {
                stack<int> s;
                s.push(i);
                while (i = ans[i])
                    s.push(i);

                printf("%d", s.size());
                while (!s.empty())
                {
                    printf(" %d", s.top());
                    s.pop();
                }
            }
            else
                printf("1 %d", i);
            putchar('\n');
        }
    }
    else
        puts("-1");

    return 0;
}