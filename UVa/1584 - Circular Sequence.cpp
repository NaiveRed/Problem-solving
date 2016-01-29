#include<cstdio>
#include<cstring>

int main()
{
    int Case;
    scanf("%d", &Case);
    getchar();

    char str[101];
    while (Case--)
    {
        gets(str);
        int len = strlen(str), ans = 0;

        //找從哪裡起始的字典序會最小
        for (int i = 1; i < len; i++)
        {
            for (int j = 0; j < len; j++)
            {
                int idx = (i + j) % len, ans_idx = (ans + j) % len;

                if (str[idx] < str[ans_idx])
                {
                    ans = i;
                    break;
                }
                else if (str[idx] > str[ans_idx])
                    break;
            }
        }

        for (int i = 0; i < len; i++)
            putchar(str[(ans + i) % len]);
        putchar('\n');
    }

    return 0;
}
