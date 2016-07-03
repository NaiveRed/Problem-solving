#include<cstdio>
#include<cstring>
#define N 201

int main()
{
    int n;
    int key[N], order[N][N];
    char str[N], ans[N];
    while (scanf("%d", &n) && n)
    {
        int i, k;
        for (i = 1; i <= n; i++) 
            scanf("%d", &key[i]);

        for (i = 1; i <= n; i++)
        {
            int temp = i, j = 0;

            do
            {
                order[i][++j] = temp;
                temp = key[temp];
            } while (i != temp);

            order[i][0] = j;//存它的週期
        }

        while (scanf("%d", &k) && k)
        {
            getchar();
            gets(str);
            
            for (i = 1; i <= n; i++)
                ans[i] = ' ';
            int len = strlen(str), m;

            for (i = 1; i <= len; i++)
            {
                m = k%order[i][0];
                ans[order[i][m + 1]] = str[i - 1];
            }

            for (i = 1; i <= n; i++)
                putchar(ans[i]);
            putchar('\n');
        }

        putchar('\n');
    }

    return 0;
}