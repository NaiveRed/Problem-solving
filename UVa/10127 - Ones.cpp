/*
�����w���|����A���F�קK�ϥΤj�ơA
�q 1 �}�l�A�P�_ n �O�_�i�㰣���A
�p����N�N�l�ƭ�10�A�[�W1�A�p���@�ӨC�����u�n�B�z2���

�Ѧ�:http://kos74185foracm.blogspot.tw/2011/12/10127-ones.html
*/
#include<cstdio>

int main()
{
    int n;
    while (scanf("%d", &n) != EOF)
    {
        int ans, now;
        int remainder = n == 1 ? 0 : 1;//�C�@�����l��

        for (ans = 1; remainder; ans++)
        {
            now = remainder * 10 + 1;
            remainder = now%n;
        }

        printf("%d\n", ans);
    }

    return 0;
}