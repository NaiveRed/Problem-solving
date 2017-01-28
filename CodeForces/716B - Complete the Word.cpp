#include<cstdio>
#include<cstring>
#define N 26

int main()
{
    char str[50002];
    fgets(str, 50002, stdin);

    int len = strlen(str) - 1;

    if (len < N)
        puts("-1");
    else
    {
        int alp[N] = {}, head = 0, count = 0, i, x = 0, need = 0;

        for (i = 0; i < N; i++)
        {
            if (str[i] == '?')
                x++;
            else
                alp[str[i] - 'A']++;
        }

        for (i = 0; i < N; i++)
            if (alp[i] == 1)
                count++;
            else if (!alp[i])
                need++;

        for (i = N; i < len; i++)
        {
            if (count == 26 || (count + need == 26 && need == x))
                break;

            if (str[head] == '?')
                x--;
            else
            {
                if (alp[str[head] - 'A'] == 1)
                    count--;
                alp[str[head] - 'A']--;
                if (alp[str[head] - 'A'] == 1)
                    count++;
                else if (!alp[str[head] - 'A'])
                    need++;
            }

            if (str[i] == '?')
                x++;
            else
            {
                if (alp[str[i] - 'A'] == 1)
                    count--;
                alp[str[i] - 'A']++;
                if (alp[str[i] - 'A'] == 1)
                {
                    count++;
                    need--;
                }
            }

            head++;
        }

        if (count == 26 || (count + need == 26 && need == x))
        {
            for (i = 0; i < head; i++)
                putchar((str[i] == '?') ? 'A' : str[i]);

            for (int k = 0, j = 0; j < 26; i++, j++)
            {
                if (str[i] == '?')
                {
                    while (alp[k] == 1)
                        k++;
                    putchar(k + 'A');
                    alp[k]++;
                    k++;
                }
                else
                    putchar(str[i]);
            }

            for(;i<len;i++)
                putchar((str[i] == '?') ? 'A' : str[i]);

            putchar('\n');
        }
        else
            puts("-1");
    }

    return 0;
}