//�u�n���b�̥��M�̥k�����a�����A���n�Ӧ^���@��^�쨮�l�A�Z�����O (max - min) *2
#include<cstdio>

int main()
{
    int Case;
    scanf("%d", &Case);
    while (Case--)
    {
        int n, i, min = 100, max = 0, num;
        scanf("%d", &n);

        for (i = 0; i < n; i++)
        {
            scanf("%d", &num);
            if (num > max)
                max = num;
            if (num < min)
                min = num;
        }

        printf("%d\n", (max - min) * 2);
    }
    return 0;
}