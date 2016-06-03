//璶氨程オ㎝程┍產ぇ丁常璶ㄓǐ诫ó禯瞒常琌 (max - min) *2
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