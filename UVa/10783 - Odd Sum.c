#include<stdio.h>

int main(){

    int set;

    while (scanf("%d", &set) != EOF)
    {
        int count;
        for (count = 1; count <= set; count++)
        {
            int a, b;

            scanf("%d%d", &a, &b);
            int i, sum = 0;

            if (a & 1)
                i = a;
            else
                i = a + 1;

            for (; i <= b; i += 2)/*�qa~b�p�G�O�_�ƴN�[�_��*/
                sum += i;

            printf("Case %d: %d\n", count, sum);
        }

    }
    return 0;
}

