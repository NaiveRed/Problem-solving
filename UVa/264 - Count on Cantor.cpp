#include<cstdio>

int main()
{
    int slash[4500] = { 0, 1 };//到每一斜排的數字個數
    for (int i = 2; i < 4500; i++)
        slash[i] = slash[i - 1] + i;

    int n;
    while (scanf("%d", &n) != EOF)
    {
        int s = 0;//第幾斜排
        for (s = 1; n > slash[s]; s++);

        if (s & 1)//偶數排時，由上到下
            printf("TERM %d IS %d/%d\n", n, slash[s] - n + 1, n - slash[s - 1]);
        else//奇數排時，由下到上
            printf("TERM %d IS %d/%d\n", n, n - slash[s - 1], slash[s] - n + 1);
    }

    return 0;
}