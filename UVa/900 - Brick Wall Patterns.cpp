/*
�j������2�A�e��1�A�ҥH
�`���� n :
1. n-1 ���[�W������
2. n-2 ���[�W���
�]�N�O�O���ƦC�C
*/
#include<cstdio>

int main()
{
    long long fib[51] = {1,1};
    
    //fibonacci
    for (int i = 2; i < 51; i++)
        fib[i] = fib[i - 1] + fib[i - 2];

    int n;
    while (scanf("%d", &n) && n)
        printf("%lld\n", fib[n]);
    
    return 0;
}
