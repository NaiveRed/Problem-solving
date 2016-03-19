#include<cstdio>

inline unsigned int reverse_bits(unsigned int n, unsigned int bit);//將 n 的二進位顛倒，bit 為總位數
int main()
{
    int Case;
    scanf("%d", &Case);

    while (Case--)
    {
        unsigned int depth, n;
        scanf("%d%d", &depth, &n);

        printf("%u\n", (1 << (depth - 1)) + reverse_bits(n - 1, depth - 1));
    }

    return 0;
}
unsigned int reverse_bits(unsigned int n, unsigned int bit)
{
    unsigned int tar = 0;
    while (bit--)
    {
        tar <<= 1;//將目前存好的左移一位
        tar |= (n & 1);//將 n 的最後一位加到 tar
        n >>= 1;//n 移掉最後一位
    }
    return tar;
}