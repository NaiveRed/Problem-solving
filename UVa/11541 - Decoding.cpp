#include <cstdio>
#include <cstring>
#include <cctype>

int main()
{
    int T;
    scanf("%d ", &T);
    for (int t = 1; t <= T; t++)
    {
        char str[205], c;
        fgets(str, 205, stdin);
        int count = 0, len = strlen(str);

        printf("Case %d: ", t);
        for (int i = 0; i < len; i++)
        {
            if (isdigit(str[i]))
                count = count * 10 + str[i] - '0';
            else
            {
                if (count)
                    for (int j = 0; j < count; j++)
                        putchar(c);
                count = 0;
                c = str[i];
            }
        }
        putchar('\n');
    }

    return 0;
}