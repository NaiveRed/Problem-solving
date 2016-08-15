#include<cstdio>
#include<cstring>

int main()
{
    int Case;
    char str1[100], str2[100];
    scanf("%d", &Case);
    getchar();
    for (int c = 1; c <= Case; c++)
    {
        fgets(str1, 100, stdin);
        fgets(str2, 100, stdin);
        int i, j, len1 = strlen(str1) - 1;
        bool wrong = false, format = true;
        for (i = 0, j = 0; i < len1; i++)
            if (str1[i] == str2[j])
                j++;
            else if (str2[j] == ' ')
            {
                j++;
                i--;
                wrong = true;
            }
            else if (str1[i] != ' ')
            {
                format = false;
                wrong = true;
                break;
            }
            else//str1[i]==' '
                wrong = true;

        printf("Case %d: ", c);
        if (!wrong)
            puts("Yes");
        else if (format&&j == strlen(str2) - 1)
            puts("Output Format Error");
        else
            puts("Wrong Answer");
    }

    return 0;
}