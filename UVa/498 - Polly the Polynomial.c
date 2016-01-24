#include<stdio.h>
#include<math.h>

int getNum(char *str, int *num);
int main(){

    char str[1001];
    int x[1000], c[1000];

    while (gets(str))
    {
        int count = getNum(str, c);
        gets(str);
        int set = getNum(str, x);

        int exp, sum, i, j;

        for (j = 0; j < set; j++)
        {
            sum = 0;
            exp = 1;
            for (i = count - 1; i >= 0; i--, exp *= x[j])
                sum += c[i] * exp;
            printf("%d%c", sum, j == set - 1 ? '\n' : ' ');
        }

    }

    return 0;
}
int getNum(char *str, int *num)
{
    int i, sum = 0, count = 0, neg = 0;
    for (i = 0; str[i]; i++)
    {
        if (str[i] == ' ')
        {
            num[count++] = sum*(neg ? -1 : 1);
            neg = sum = 0;
        }
        else if (str[i] == '-')
            neg = 1;
        else
            sum = sum * 10 + str[i] - '0';
    }

    num[count++] = sum*(neg ? -1 : 1);
    return count;
}
