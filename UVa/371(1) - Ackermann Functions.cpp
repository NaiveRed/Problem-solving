//time: 0.050
#include <cstdio>
typedef unsigned int UI;

inline int f(UI n)
{
    int count = 0;
    do
    {
        if (n & 1)
            n = (n << 1) + n + 1;
        else
            n >>= 1;
        count++;
    } while (n != 1);

    return count;
}
int main()
{
    int L, H;
    while (scanf("%d%d", &L, &H) && (L || H))
    {
        //L 可能大於 H
        if (L > H)
        {
            int tmp = L;
            L = H;
            H = tmp;
        }

        int max, val = 0;
        for (int i = L; i <= H; i++)
        {
            int tmp = f(i);
            if (tmp > val)
            {
                max = i;
                val = tmp;
            }
        }

        printf("Between %d and %d, %d generates the longest sequence of %d values.\n", L, H, max, val);
    }

    return 0;
}