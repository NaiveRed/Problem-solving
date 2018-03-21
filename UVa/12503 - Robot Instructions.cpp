#include <cstdio>

int main()
{
    //freopen("test.out", "w", stdout);
    int T;
    char str[15];
    scanf("%d", &T);
    while (T--)
    {
        int n, pos = 0, com[101];
        scanf("%d ", &n);
        for (int i = 1; i <= n; ++i)
        {
            fgets(str, 15, stdin);
            if (str[0] == 'L')
                com[i] = -1;
            else if (str[0] == 'R')
                com[i] = 1;
            else
            {
                int tmp = 0;
                 for (int j = 8; str[j] != '\n'; ++j)
                    tmp = tmp * 10 + str[j] - '0';
                com[i] = com[tmp];
            }

            pos += com[i];
        }

        printf("%d\n", pos);
    }

    return 0;
}