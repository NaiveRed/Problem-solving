#include<cstdio>

inline unsigned int reverse_bits(unsigned int n, unsigned int bit);//�N n ���G�i���A�ˡAbit ���`���
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
        tar <<= 1;//�N�ثe�s�n�������@��
        tar |= (n & 1);//�N n ���̫�@��[�� tar
        n >>= 1;//n �����̫�@��
    }
    return tar;
}