#include<cstdio>
#include<cstring>
#include<cctype>
#define N 1000

int main()
{
    char str[N];
    while (gets(str))
    {
        int count[52] = {};//0~25存大寫的次數，26~51存小寫的次數
        int i, len = strlen(str);
        for (i = 0; i < len; i++)
        {
            if (isalpha(str[i]))
            {
                if (str[i] <= 'Z'&&str[i] >= 'A')
                    count[str[i] - 'A']++;
                else
                    count[str[i] - 'a' + 26]++;
            }
        }

        int max = 0;
        for (i = 0; i < 52; i++)
            if (max < count[i])
                max = count[i];

        for (i = 0; i <= 25; i++)
            if (count[i] == max)
                putchar(i + 'A');
        for (i = 0; i <= 25; i++)
            if (count[i + 26] == max)
                putchar((i + 'a'));

        printf(" %d\n", max);
    }

    return 0;
}