#include <cstdio>

int main()
{

    int n;
    while (scanf("%d", &n) != EOF)
    {
        //for one byte(1111 1111 = 255)
        int b = 255, nn = n;
        int ans = n & b;

        for (int i = 0; i < 3; i++) //shift 3 times
        {
            nn >>= 8;
            ans <<= 8;
            ans |= nn & b;
            //printf("%d %d\n", nn,ans);
        }
        printf("%d converts to %d\n", n, ans);
    }

    return 0;
}