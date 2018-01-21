#include <cstdio>
#include <cstring>
#define N 1000005

char str[N];
int count[N];
int main()
{
    int Case = 1;
    while (fgets(str, N, stdin) && str[0] != '\n')
    {
        int len = strlen(str) - 1;
        count[0] = str[0] - '0';
        for (int i = 1; i < len; i++)
            count[i] = count[i - 1] + (str[i] != str[i - 1] ? 1 : 0); //與前一個不同就將編號加一
        printf("Case %d:\n", Case++);
        int n;
        scanf("%d", &n);
        while (n--)
        {
            int a, b;
            scanf("%d%d", &a, &b);
            if (count[a] != count[b])
                puts("No");
            else
                puts("Yes");
        }
        getchar();
    }

    return 0;
}