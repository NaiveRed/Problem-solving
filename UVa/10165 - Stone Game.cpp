//http://calculus.nctu.edu.tw/upload/calculus_web/maple/Site/carnival/game/202.htm
#include<cstdio>

int main()
{
    int n;
    while (scanf("%d", &n) && n)
    {
        int ans = 0;
        while (n--)
        {
            int temp;
            scanf("%d", &temp);
            ans ^= temp;
        }
        puts(ans ? "Yes" : "No");
    }

    return 0;
}