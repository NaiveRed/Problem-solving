#include<cstdio>

int main()
{
    int slash[4500] = { 0, 1 };//��C�@�ױƪ��Ʀr�Ӽ�
    for (int i = 2; i < 4500; i++)
        slash[i] = slash[i - 1] + i;

    int n;
    while (scanf("%d", &n) != EOF)
    {
        int s = 0;//�ĴX�ױ�
        for (s = 1; n > slash[s]; s++);

        if (s & 1)//���ƱƮɡA�ѤW��U
            printf("TERM %d IS %d/%d\n", n, slash[s] - n + 1, n - slash[s - 1]);
        else//�_�ƱƮɡA�ѤU��W
            printf("TERM %d IS %d/%d\n", n, n - slash[s - 1], slash[s] - n + 1);
    }

    return 0;
}