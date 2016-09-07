#include<cstdio>
#include<cstring>

int main()
{
    const int mod[10] = { 1,1,4,4,2,1,1,4,4,2 };
    
    //循環的順序，為方便 index 計算將每個數的最後一個循環移到第一個
    const int ans[10][4] = { {0},{1},{6,2,4,8},{1,3,9,7},{6,4},{5},{6},{1,7,9,3},{6,8,4,2},{1,9} };
    char sm[105], sn[105];
    while (scanf("%s%s", sm, sn) && (sm[0] != '0' || sn[0] != '0'))
    {
        if (sn[0] == '0')
        {
            puts("1");
            continue;
        }

        int len_m = strlen(sm), len_n = strlen(sn), m = sm[len_m - 1] - '0', n = 0;

        //邊 mod 邊算 n 的值
        for (int i = 0; i <len_n ; i++)
        {
            n = n * 10 + sn[i] - '0';
            n %= mod[m];
        }

        printf("%d\n", ans[m][n]);
    }

    return 0;
}