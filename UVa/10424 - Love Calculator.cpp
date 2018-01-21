#include <cstdio>
#include <cstring>
#include <cctype>

inline int sum_digits(int n)
{
    int ret = 0;
    while (n)
    {
        ret += n % 10;
        n /= 10;
    }
    return ret;
}
int main()
{
    char str1[27], str2[27];

    while (fgets(str1, 27, stdin))
    {
        fgets(str2, 27, stdin);
        int n1 = 0, n2 = 0, len1 = strlen(str1), len2 = strlen(str2);

        for (int i = 0; i < len1 - 1; i++)
        {
            if (isalpha(str1[i]))
                n1 += tolower(str1[i]) - 'a' + 1;
        }

        for (int i = 0; i < len2 - 1; i++)
        {
            if (isalpha(str2[i]))
                n2 += tolower(str2[i]) - 'a' + 1;
        }

        while (n1 >= 10)
            n1 = sum_digits(n1);
        while (n2 >= 10)
            n2 = sum_digits(n2);

        printf("%.2f %%\n", n1 > n2 ? (float)n2 / n1 * 100 : (float)n1 / n2 * 100);
    }

    return 0;
}