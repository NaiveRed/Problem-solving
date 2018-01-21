#include <cstdio>

int main()
{
    int N;
    scanf("%d", &N);
    while (N--)
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        if (a + b > c && a + c > b && c + b > a) //三角不等式
            puts("OK");
        else
            puts("Wrong!!");
    }

    return 0;
}