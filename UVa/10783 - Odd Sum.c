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

            for (; i <= b; i += 2)/*從a~b如果是奇數就加起來*/
                sum += i;

            printf("Case %d: %d\n", count, sum);
        }

    }
    return 0;
}

