#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 100001
int main()
{
    char str[N], rev[N];
    while (gets(str))
    {
        int fail[N] = { -1 }, len = strlen(str), i, j;
        std::reverse_copy(str, str + len, rev);
        
        //rev's failure function
        for (i = 1, j = -1; i < len; ++i)
        {
            while (j >= 0 && rev[j + 1] != rev[i])
                j = fail[j];
            if (rev[j + 1] == rev[i])
                ++j;
            fail[i] = j;
        }

        //¤Ç°t
        for (i = 0, j = -1; i < len; ++i)
        {
            while (j >= 0 && rev[j + 1] != str[i])
                j = fail[j];

            if (rev[j + 1] == str[i])
                ++j;
        }

        for (i = 0; i < len; ++i)
            putchar(str[i]);
        for (++j; j < len; ++j)
            putchar(rev[j]);
        putchar('\n');
    }

    return 0;
}