#include<cstdio>
#include<cctype>
#include<deque>
#include<cstring>
using namespace std;

char str[100];
deque<int> num;
void solve();
int main()
{
    while (fgets(str, 100, stdin) && str[0] != '*')
    {
        str[strlen(str) - 1] = NULL;
        solve();
        num.clear();
    }

    return 0;
}
void solve()
{
    int len = strlen(str), i, k;
    int base, tar, tran, size = 1;
    if (isdigit(str[0]))
        base = 10, tar = 26, tran = '0';
    else
        base = 26, tar = 10, tran = 'a' - 1;

    //��r���ন�Ʀr
    for (i = 0; i < len; i++)
    {
        if (i)
        {
            size = num.size();

            //���N�p�⦸��
            for (k = 0; k < size; k++)
                num[k] *= base;
            num[size - 1] += (str[i] - tran);
        }
        else//�٨S���Ʀr��
            num.push_back(str[i] - tran);

        //�B�z�i��
        for (k = size - 1; k; k--)
            if (num[k] >= tar)
            {
            num[k - 1] += (num[k] / tar);
            num[k] %= tar;
            }

        //�̰���
        while (num[0] >= tar)
        {
            num.push_front(num[0] / tar);
            num[1] %= tar;
        }
    }

    size = num.size();
    if (base == 10)//�ন�^��r��
    {
        /*
        �B�z�S�� 0 �����D:

        �N�C�� num[] �u�n�O 0 �A�N�N��e�@���@�A�p�G�e�@��]�O 0 �N�ɦ쪽�줣�� 0 ���C
        */
        for (i = size - 1; i; i--)
        {
            if (!num[i])
            {
                for (int j = i - 1; j >= 0; j--)
                    if (!num[j])
                        num[j] = 25;
                    else
                    {
                        num[j]--;
                        break;
                    }
            }
        }

        int temp = 0;
        //�p�G�Ĥ@��O 0 �h�N��ɦ�ɱ��F(�D z)
        for (i = num[0] ? 0 : 1; i < size; i++)
        {
            putchar(num[i] ? ('a' + num[i] - 1) : 'z');//0 �� z�A��l�n�� 1 �~�O�N���r��
            temp++;
        }

        //�榡�B�z
        for (; temp < 22; temp++)
            putchar(' ');
        i = 0;
        int count = len % 3;
        if (count)//�h�X�Ӫ�
        {
            for (i = 0; i < count; i++)
                putchar(str[i]);
            if (len > 3)
                putchar(',');
        }

        count = 0;
        for (; i < len; i++, count++)
        {
            if (count == 3)
            {
                putchar(',');
                count = 0;
            }
            putchar(str[i]);
        }

        putchar('\n');
    }
    else//�ন�Ʀr(decimal)
    {
        printf("%-22s", str);

        int  count;

        count = size % 3;
        i = 0;
        if (count)//�h�X�Ӫ�
        {
            while (count--)
                putchar('0' + num[i++]);

            if (size > 3)
                putchar(',');
        }

        count = 0;
        for (; i < size; i++, count++)
        {
            if (count == 3)
            {
                putchar(',');
                count = 0;
            }

            putchar('0' + num[i]);
        }
        putchar('\n');
    }
}