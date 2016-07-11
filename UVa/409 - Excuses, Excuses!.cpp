#include<cstdio>
#include<cctype>
#include<cstring>

char key[20][30];
inline int check(char word[], int K)
{
    int j, count = 0;
    for (j = 0; j < K; j++)//key
    {
        if (!strcmp(key[j], word))
        {
            count++;
            break;
        }
    }

    return count;
}
int main()
{
    int K, E, Case = 1;
    char  excuse[20][75], str[75];
    while (scanf("%d%d%*c", &K, &E) != EOF)
    {
        int i, j, count[20] = {};
        char word[30];
        for (i = 0; i < K; i++)
            gets(key[i]);

        for (i = 0; i < E; i++)
        {
            gets(excuse[i]);
            for (j = 0; excuse[i][j]; j++)
                if (!isalpha(excuse[i][j]))
                    str[j] = ' ';
                else
                    str[j] = tolower(excuse[i][j]);
            excuse[i][j] = str[j] = NULL;

            bool flag = false;
            int len = strlen(str), idx = 0;
            for (int s = 0; s < len; s++)
            {
                if (str[s] != ' ')
                {
                    word[idx++] = str[s];
                    if (!flag)
                        flag = true;
                }
                else if (flag)
                {
                    flag = false;
                    word[idx] = NULL;
                    count[i] += check(word, K);
                    idx = 0;
                }
            }
            if (str[len - 1] != ' ')//最後一個word還沒算到
            {
                word[idx] = NULL;
                count[i] += check(word, K);
            }
        }

        int max = 0;
        for (i = 0; i < E; i++)
            if (max < count[i])
                max = count[i];

        printf("Excuse Set #%d\n", Case++);
        for (i = 0; i < E; i++)
            if (count[i] == max)
                puts(excuse[i]);
        putchar('\n');
    }

    return 0;
}