/*
�Ѧ�:http://woriheck.blogspot.tw/2013/08/10093-easy-problem.html

�Y�@��n�i�쪺�ƥi�H�Qn - 1�㰣�A�h���C�Ӧ�ƪ��`�M�]�|�Qn - 1�㰣�C

*/
#include<cstdio>
#include<cstring>

inline int findBase(char *str, int& sum);//��X�Ʀr�C�@�줤�̤j��(�ݷ|����l�򩳤��i�p��)�A�ìۥ[�C�@���
int main()
{
    char str[10001];

    while (gets(str))
    {
        int sum;
        int max = findBase(str, sum) , i;

        for (i = max; i < 62; i++)
            if (!(sum%i))
            {
            printf("%d\n", i + 1);
            break;
            }

        if (i == 62)
            puts("such number is impossible!");
    }

    return 0;
}
int findBase(char *str, int& sum)
{
    sum = 0;
    int i, max = 1, len = strlen(str), temp;
    for (i = 0; i < len; i++)
    {
        if (str[i] >= '0'&&str[i] <= '9')
        {
            temp = str[i] - '0';
            if (max < temp)
                max = temp;
            sum += temp;
        }
        else if (str[i] >= 'A'&&str[i] <= 'Z')
        {
            temp = str[i] - 'A' + 10;
            if (max < temp)
                max = temp;
            sum += temp;
        }
        else if (str[i] >= 'a'&&str[i] <= 'z')
        {
            temp = str[i] - 'a' + 36;
            if (max < temp)
                max = temp;
            sum += temp;
        }
    }

    return max;
}