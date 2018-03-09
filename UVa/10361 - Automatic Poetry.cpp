#include <cstdio>
#define N 105

int main()
{
    int n;
    scanf("%d ", &n);
    while (n--)
    {
        char str1[N], str2[N];
        fgets(str1, N, stdin);
        fgets(str2, N, stdin);

        int lt1 = -1, gt1 = -1, lt2 = -1, gt2 = -1; //position of <,>,<,>
        for (int i = 0; str1[i] != '\n'; ++i)
        {
            if (str1[i] == '<')
            {
                if (lt1 != -1)
                    lt2 = i;
                else
                    lt1 = i;
            }
            else if (str1[i] == '>')
            {
                if (gt1 != -1)
                    gt2 = i;
                else
                    gt1 = i;
            }
            else
                putchar(str1[i]);
        }

        putchar('\n');

        for (int i = 0; str2[i] != '\n'; ++i)
        {
            if (str2[i] != '.')
                putchar(str2[i]);
            else
                break;
        }

        //s_4
        for (int i = lt2 + 1; i < gt2; ++i)
            putchar(str1[i]);
        //s_3
        for (int i = gt1 + 1; i < lt2; ++i)
            putchar(str1[i]);
        //s_2
        for (int i = lt1 + 1; i < gt1; ++i)
            putchar(str1[i]);
        //s_5
        for (int i = gt2 + 1; str1[i] != '\n'; ++i)
            putchar(str1[i]);
        putchar('\n');
    }

    return 0;
}