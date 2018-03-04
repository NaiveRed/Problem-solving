#include <cstdio>

int main()
{

    int L[2], R[2], M[2]; //[0]: denominator, [1]: numerator
    int n[2];
    while (scanf("%d%d", &n[1], &n[0]) && (n[0] != 1 || n[1] != 1))
    {
        L[0] = 1;
        L[1] = 0;
        R[0] = 0;
        R[1] = 1;
        M[0] = M[1] = 1;

        while (M[0] != n[0] || M[1] != n[1])
        {
            //擴分比大小
            if (n[1] * M[0] > M[1] * n[0]) //大於根
            {
                putchar('R');

                //update R, M
                int m0 = M[0], m1 = M[1];
                M[0] += R[0];
                M[1] += R[1];
                L[0] = m0;
                L[1] = m1;
            }
            else
            {
                putchar('L');

                //update L, M
                int m0 = M[0], m1 = M[1];
                M[0] += L[0];
                M[1] += L[1];
                R[0] = m0;
                R[1] = m1;
            }
        }

        putchar('\n');
    }

    return 0;
}