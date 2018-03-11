#include <cstdio>

void gcdEX(int a, int b, int &i, int &j, int &d)
{
    if (b == 0)
    {
        d = a; // 最大公因數為 a
        i = 1;
        j = 0; // 此時的 i j
        return;
    }

    gcdEX(b, a % b, i, j, d);

    int t = i;
    i = j;
    j = t - (a / b) * j;
}
inline int get_num()
{
    int n = 0;
    char c;
    while ((c = getchar()) != '\n' && c != ' ' && c != EOF)
        n = n * 10 + c - '0';
    if (c == EOF)
        return -1;
    return n;
}
int main()
{
    int a, b;
    while ((a = get_num()) != -1)
    {
        b = get_num();
        int i, j, d;
        gcdEX(a, b, i, j, d);
        printf("%d %d %d\n", i, j, d);
    }

    return 0;
}