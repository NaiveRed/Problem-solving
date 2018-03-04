//ref: http://blog.csdn.net/u012773338/article/details/42006693
#include <cstdio>

int main()
{
    int n;
    while (scanf("%d", &n) != EOF)
    {
        int sum = 1, n2 = 0, n5 = 0;

        //計算 n! 有幾個 2 和 5，並事先移掉，避免尾數是零的狀況
        for (int i = 2; i <= n; i++)
        {
            int tmp = i;
            while (!(tmp & 1))
            {
                n2++;
                tmp >>= 1;
            }
            while (!(tmp % 5))
            {
                n5++;
                tmp /= 5;
            }
            sum = (sum * tmp) % 10;
        }

        //補上剩餘的 2，由於 5 都已經去除，並不會造成尾數等於 0
        for (int i = 0; i < n2 - n5; i++)
            sum = (sum << 1) % 10;

        printf("%5d -> %d\n", n, sum);
    }

    return 0;
}