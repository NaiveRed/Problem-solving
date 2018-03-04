#include <cstdio>

inline void swap(int &a, int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
}
int main()
{
    int a, b; //分子,分母
    while (scanf("%d%d", &a, &b) != EOF)
    {
        /*
        a/b 轉成帶分數，其整數部分即是 b_i。
        接著將分子分母顛倒(分子較大)。
        重複上面步驟，直到 a 被 b 整除 ( swap(a, b) 後 b = 0 )
        */
        bool first = true;
        printf("[%d;", a / b);
        a %= b;
        swap(a, b);

        while (b)
        {
            if (first)
                first = false;
            else
                putchar(',');

            printf("%d", a / b);
            a %= b;
            swap(a, b);
        }

        puts("]");
    }

    return 0;
}