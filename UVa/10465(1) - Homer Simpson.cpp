#include<cstdio>

inline int input();
int main()
{
    int a, b, t;
    while ((a = input()) != EOF)
    {
        b = input();
        t = input();

        //�p����
        if (a > b)
        {
            int temp = a;
            a = b;
            b = temp;
        }

        int time = t;
        int eat = t / a;//�Y a �~�����ƶq
        t %= a;//�Y�� a ��ҳѾl���ɶ�

        if (t)
        {
            //��� a ���ƶq�Ӵ� b
            for (int i = eat; i >= 0; i--)//�ѤW���U���A�b�ɶ��Q�Χ������p�U�~���Ƭ��̦h
            {
                int remain = time - i*a;//�ثe�ѤU���ɶ�
                if (!(remain % b))//�i�H��ɶ��Q�Χ�
                {
                    eat = i + remain / b;
                    t = 0;
                    break;
                }

                //�P�_���ɦY�� b �~���᪺�Ѿl�ɶ��O�_���
                if (remain % b < t)
                {
                    t = remain % b;
                    eat = i + remain / b;
                }
            }
        }

        if (t)
            printf("%d %d\n", eat, t);
        else
            printf("%d\n", eat);
    }

    return 0;
}
int input()
{
    int n = 0;
    char c;
    while ((c = getchar()) != ' '&&c != '\n')
    {
        if (c == EOF)
            return -1;
        n = n * 10 + c - '0';
    }
    return n;
}