#include<stdio.h>

long long re(long long n);//�N�Ʀr�A��
int main(){

    int set;
    long long num, temp;

    while (scanf("%d", &set) != EOF)
    {
        for (; set > 0; set--)
        {
            scanf("%lld", &num);

            int count = 0;

            //while ( (temp = re(num)) != num||!count)//zeorjudge �W ����N�j�媺���ݰ��@����A�~��P�_
            while ((temp = re(num)) != num)//�N�Ʀr�A�˫�A�P�_�O�_�j��
            {
                num += temp;//�쥻���[�W�A�˫᪺�����s���Ʀr
                count++;

            }

            printf("%d %lld\n", count, temp);
        }

    }
    return 0;
}

long long re(long long n)
{
    long long temp = 0;

    while (n)
    {
        temp = temp * 10 + n % 10;
        n /= 10;

    }
    return temp;
}