#include<stdio.h>
#include<string.h>

int main()
{
    char rev[] = "A   3  HIL JM O   2TUVWXY51SE Z  8 ";
    char str[21];

    while (gets(str))
    {
        int len = strlen(str);
        int isP = 1, isM = 1, i;

        for (i = 0; i < len; i++)
            if (str[i] != str[len - i - 1])
            {
            isP = 0;
            break;
            }

        for (i = 0; i < len; i++)
        {
            char c;
            if (str[i] >= '0'&&str[i] <= '9')
                c = rev[str[i] - '1' + 26];
            else
                c = rev[str[i] - 'A'];

            if (str[len-i-1] != c)
            {
                isM = 0;
                break;
            }
        }

        if (isP)
            printf("%s%s\n\n", str, isM ? " -- is a mirrored palindrome." : " -- is a regular palindrome.");
        else
            printf("%s%s\n\n", str, isM ? " -- is a mirrored string." : " -- is not a palindrome.");
    }

    return 0;
}