#include <cstdio>
#include <cmath>

char str[11];
inline int read()
{
    fgets(str, 11, stdin);
    if (str[0] == '0')
        return 0;

    int n = 0;
    for (int i = 0; str[i] != '\n'; ++i)
        n = n * 10 + str[i] - '0';
    return n;
}
int main()
{
    int s;
    while ((s = read()) != 0)
    {
        int s2 = s << 1;
        /*
        //n^2 - n - 2s <= 0
        int n = ceil(sqrt((double)(s2)));        
        int nn = n * n;
        if (nn - n > (s << 1))
        {
            nn -= (n << 1) - 1; //(n)^2 - (n*2-1) = (n-1)^2
            --n;
        }
        printf("%d %d\n", ((nn + n) >> 1) - s, n);
        */

        //n^2 + n - 2s > 0
        int n = floor(sqrt((double)(s2)));
        int nn1 = n * (n + 1);
        if (nn1 <= s2)
        {
            nn1 += (++n) << 1; //(n*(n+1)) + (n+1)*2 = (n+1)*(n+2)
            //++n;
        }
        printf("%d %d\n", (nn1 >> 1) - s, n);
    }

    return 0;
}