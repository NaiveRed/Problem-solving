#include<stdio.h>

typedef long long LL;
LL getNum();
int main(){

    LL M[10001];
    int Case, k;
    scanf("%d", &Case);
    getchar();

    for (k = 1; k <= Case; k++)
    {
        int N, i;
        scanf("N = %d", &N);
        getchar();
        int arrIdx = N*N, isSymmetric = 1;

        /*
        存成一維陣列，如果對稱，將會是迴文
        P.S. 有負數即為不對稱(題目定義)
        */
        for (i = 1; i <= arrIdx; i++)
        {
            M[i] = getNum();
            if (M[i] < 0)
                isSymmetric = 0;
        }

        if (isSymmetric)
        {
            int mid = arrIdx / 2;
            for (i = 1; i <= mid; i++)
            {
                if (M[i] < 0 || M[arrIdx - i + 1] < 0 || M[i] != M[arrIdx - i + 1])
                {
                    isSymmetric = 0;
                    break;
                }
            }
        }
        printf("Test #%d: %symmetric.\n", k, isSymmetric ? "S" : "Non-s");
    }
    return 0;
}
LL getNum()
{
    LL num = 0;
    int neg = 0;
    char c;
    while ((c = getchar()) != ' '&&c != '\n')
    {
        if (c == '-')
            neg = 1;
        else
            num = num * 10 + c - '0';
    }
    return num*(neg ? -1 : 1);
}