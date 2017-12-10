//參考: http://justimchung.blogspot.tw/2017/11/uva-13178-is-it-multiple-of-3.html
#include <cstdio>

int main()
{
    int Case;
    scanf("%d", &Case);
    while (Case--)
    {
        int n;
        scanf("%d", &n);
        puts((n - 1) % 3 ? "YES" : "NO");
    }

    return 0;
}