#include<cstdio>
#include<stack>
#define N 130

int main()
{
    std::stack<char> parentheses;
    int n,i;
    char s[N] = { NULL };
    scanf("%d", &n);

    getchar();
    while (n--)
    {
        fgets(s, N, stdin);

        for (i = 0; s[i] != '\n'; i++)
        {
            if (s[i] == '(' || s[i] == '[')
                parentheses.push(s[i]);
            else if (s[i] == ')')
            {
                if (!parentheses.empty() && parentheses.top() == '(')
                    parentheses.pop();
                else
                    break;
            }
            else if (s[i] == ']')
            {
                if (!parentheses.empty() && parentheses.top() == '[')
                    parentheses.pop();
                else
                    break;
            }
        }

        printf("%s\n", parentheses.empty() && s[i] == '\n' ? "Yes" : "No");

        while (!parentheses.empty())
            parentheses.pop();
    }


    return 0;
}