#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

struct Num
{
    int sum_digit;
    char str[10];
}num[10];
bool comp(const Num& a, const Num& b);
int main()
{
    int Case;
    scanf("%d", &Case);
    while (Case--)
    {
        char c;
        int n, i, j, sum = 0;
        scanf("%d", &n);
        getchar();
        for (i = 0, j = 0; i < n; i++, j = 0, sum = 0)
        {
            while ((c = getchar()) != ' '&&c != '\n')
            {
                sum += c - '0';
                num[i].str[j++] = c;
            }
            num[i].str[j] = '\0';
            num[i].sum_digit = sum;
        }

        sort(num, num + n, comp);
        printf("%s", num[0].str);
        for (i = 1; i < n; i++)
            printf(" %s", num[i].str);
        putchar('\n');
    }

    return 0;
}
bool comp(const Num& a, const Num& b)
{
    if (a.sum_digit == b.sum_digit)
    {
        int len_a = strlen(a.str), len_b = strlen(b.str);
        if (len_a == len_b)
        {
            for (int i = 0;; i++)
                if (a.str[i] != b.str[i])
                    return a.str[i] < b.str[i];
        }
        else
            return len_a < len_b;
    }

    return a.sum_digit < b.sum_digit;
}