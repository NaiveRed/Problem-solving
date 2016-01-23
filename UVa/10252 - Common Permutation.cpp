/*
P.S. 若同字母出現不只一次，請重複印出但不能超過任一字串中出現的次數
*/
#include<cstdio>
#include<cstring>
#define MIN(a,b) ((a)<(b)?(a):(b))

int main()
{
    char str[1001];
    int ans[26];

    while (gets(str))
    {
        int count1[26] = {}, count2[26] = {};
        int len1 = strlen(str);

        if (len1)
            for (int i = 0; i < len1; i++)
                count1[str[i] - 'a']++;

        gets(str);
        int len2 = strlen(str);
        for (int i = 0; i < len2; i++)
            count2[str[i] - 'a']++;

        if (len1&&len2)
        {
            for (int i = 0; i < 26; i++)
                ans[i] = MIN(count1[i], count2[i]);

            for (int i = 0; i < 26; i++)
                for (int j = 0; j < ans[i]; j++)
                    putchar(i + 'a');

            putchar('\n');
        }
        else
            putchar('\n');

    }

    return 0;
}