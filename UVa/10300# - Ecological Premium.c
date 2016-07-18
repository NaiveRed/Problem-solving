#include<stdio.h>

int main(){

    int set, farmer, i, size, animal, num;

    scanf("%d", &set);

    while (set--)
    {
        long long sum = 0;
        scanf("%d", &farmer);
        for (i = 1; i <= farmer; i++)
        {
            scanf("%d%d%d", &size, &animal, &num);
            sum += ((long long)size*num);
        }

        printf("%lld\n", sum);
    }

    return 0;
}