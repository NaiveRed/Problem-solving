/*
钡祑埃穦犯磷ㄏノ计
眖 1 秨﹍耞 n 琌俱埃ウ
ぃ︽碞盢緇计101ㄓ–Ω常璶矪瞶2计

把σ:http://kos74185foracm.blogspot.tw/2011/12/10127-ones.html
*/
#include<cstdio>

int main()
{
    int n;
    while (scanf("%d", &n) != EOF)
    {
        int ans, now;
        int remainder = n == 1 ? 0 : 1;//–Ω緇计

        for (ans = 1; remainder; ans++)
        {
            now = remainder * 10 + 1;
            remainder = now%n;
        }

        printf("%d\n", ans);
    }

    return 0;
}