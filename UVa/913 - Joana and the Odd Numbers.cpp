#include<cstdio>

int main() {

    long long n, i, sum;
    while (scanf("%lld", &n) != EOF)
    {
        i = (1 + n)*(n / 2 + 1) / 2;//總共有幾個奇數
        sum = 3 * (1 + 2 * (i - 2));//最後 3 個相加 = 中間那個 * 3
        printf("%lld\n", sum);
    }
    return 0;
}