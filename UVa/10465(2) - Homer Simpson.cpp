#include<cstdio>

int main()
{
    int burger[2], eat[10000], t;

    while (scanf("%d%d%d", &burger[0], &burger[1], &t) != EOF)
    {
        int i, j;
        eat[0] = 0;
        for (i = 1; i <= t; i++)
            eat[i] = -1;

        //-1 ���L�k��o���Aeat ��Ӯɶ��i�Y���~����
        for (i = 0; i < 2; i++)
            for (j = burger[i]; j <= t; j++)
            {
            if (eat[j - burger[i]] != -1)
                if (eat[j - burger[i]] + 1 > eat[j])
                    eat[j] = eat[j - burger[i]] + 1;
            }
        
        //eat �� index �N��ɶ��A�ҥH�q�W���U���A�p�G�S��k�������ӧ��ɶ��A�N�|��̱���C
        for (i = t; i >= 0; i--)
            if (eat[i] != -1)
            {
            printf("%d", eat[i]);
            break;
            }

        if (i != t)
            printf(" %d", t - i);

        putchar('\n');
    }

    return 0;
}