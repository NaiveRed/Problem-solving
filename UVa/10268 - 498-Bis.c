#include<stdio.h>
#include<math.h>

char str[1000001];
int num[1000000];
int getNum();
int main(){

    int x;

    while (scanf("%d", &x) != EOF)
    {
        getchar();
        gets(str);
        int count = getNum(), i;
        int exp = 1, sum = 0;

        for (i = count - 2; i >= 0; i--, exp *= x)
            sum += num[i] * (count - i - 1)*exp;

        printf("%d\n", sum);

    }

    return 0;
}
int getNum()
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
