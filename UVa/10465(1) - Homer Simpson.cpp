#include<cstdio>

inline int input();
int main()
{
    int a, b, t;
    while ((a = input()) != EOF)
    {
        b = input();
        t = input();

        //小的先
        if (a > b)
        {
            int temp = a;
            a = b;
            b = temp;
        }

        int time = t;
        int eat = t / a;//吃 a 漢堡的數量
        t %= a;//吃完 a 後所剩餘的時間

        if (t)
        {
            //減少 a 的數量來湊 b
            for (int i = eat; i >= 0; i--)//由上往下做，在時間利用完的情況下漢堡數為最多
            {
                int remain = time - i*a;//目前剩下的時間
                if (!(remain % b))//可以把時間利用完
                {
                    eat = i + remain / b;
                    t = 0;
                    break;
                }

                //判斷此時吃掉 b 漢堡後的剩餘時間是否更少
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