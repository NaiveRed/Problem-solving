#include<cstdio>

int main() {

    long long n, i, sum;
    while (scanf("%lld", &n) != EOF)
    {
        i = (1 + n)*(n / 2 + 1) / 2;//�`�@���X�ө_��
        sum = 3 * (1 + 2 * (i - 2));//�̫� 3 �Ӭۥ[ = �������� * 3
        printf("%lld\n", sum);
    }
    return 0;
}