#include<stdio.h>

long long re(long long n);//將數字顛倒
int main(){

    int set;
    long long num, temp;

    while (scanf("%d", &set) != EOF)
    {
        for (; set > 0; set--)
        {
            scanf("%lld", &num);

            int count = 0;

            //while ( (temp = re(num)) != num||!count)//zeorjudge 上 原先就迴文的仍需做一次後再繼續判斷
            while ((temp = re(num)) != num)//將數字顛倒後，判斷是否迴文
            {
                num += temp;//原本的加上顛倒後的成為新的數字
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