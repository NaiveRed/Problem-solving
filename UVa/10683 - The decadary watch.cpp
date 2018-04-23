#include <cstdio>
#define ORD(c) ((c) - '0')

int main()
{
    //兩種計算方式的一天總 CC 的比例
    const double ratio = 1.15740740741;
    //const double ratio = (double)(10 * 100 * 100 * 100) / (24 * 60 * 60 * 100);
    const int C_convert[4] = {360000, 6000, 100, 1};
    //const int H_C = 60 * 60 * 100, M_C = 60 * 100, S_C = 100;
    char str[10];
    while (fgets(str, 10, stdin))
    {
        /*
        printf("%07d\n", (int)(ratio * (360000 * (ORD(str[0]) * 10 + ORD(str[1])) + 6000 * (ORD(str[2]) * 10 + ORD(str[3])) +
                                        100 * (ORD(str[4]) * 10 + ORD(str[5])) + (ORD(str[6]) * 10 + ORD(str[7])))));
        */
        
        int CC = 0;
        for (int i = 0; i < 4; ++i)
            CC += C_convert[i] * (ORD(str[i << 1]) * 10 + ORD(str[(i << 1) + 1]));
        CC *= ratio;
        
        printf("%07d\n", CC);
        
        /*
        int H = ORD(str[0]) * 10 + ORD(str[1]);
        int M = ORD(str[2]) * 10 + ORD(str[3]);
        int S = ORD(str[4]) * 10 + ORD(str[5]);
        int C = ORD(str[6]) * 10 + ORD(str[7]);
        int CC = ratio * (H * H_C + M * M_C + S * S_C + C); //轉換成100制的時間CC      
        H = CC / 1000000;
        CC %= 1000000;
        M = CC / 10000;
        CC %= 10000;
        S = CC / 100;
        CC %= 100;
        printf("%d%02d%02d%02d\n", H, M, S, CC);
        */
    }

    return 0;
}