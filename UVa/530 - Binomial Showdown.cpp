#include<cstdio>

int main()
{
    int n, m;
    while (scanf("%d%d", &n, &m) && n)
    {
        if (n - m < m)//�ϭ��������ܤ֡A�H�K�W��
            m = n - m;
        double ans = 1;
        for (int i = n, j = 1; j <= m; j++,i--)
        {
            ans *= i;
            ans /= j;//�q�p���}�l���A�̲׵��׬O��ơA�ҥH�̫�@�w������
        }
        printf("%.0lf\n", ans);
    }

    return 0;
}