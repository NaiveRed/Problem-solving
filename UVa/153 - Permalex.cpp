//康托展開
#include<cstdio>
#include<cstring>
#define N 31
typedef long long LL;
inline int gcd(int a, int b);
int main()
{
    char str[N];
    while (gets(str) && str[0] != '#')
    {
        int i, j, k, len = strlen(str);
        int alp[26] = {};

        //計算字母數
        for (i = 0; i < len; i++)
            alp[str[i] - 'a']++;

        LL ans = 0;
        for (i = 0; i < len; i++)
        {
            for (j = 0; j < str[i] - 'a'; j++)//每個小於 str[i] 的字母
            {
                if (!alp[j])
                    continue;

                int back = len - i - 1;//str[i] 後方的字母個數
                
                alp[j]--;//以 j + 'a' (字母)當頭

                //分子
                int num[N] = {};
                for (k = 0; k <= back; k++)
                    num[k] = k;

                //處理相同字母多於一時
                for (k = 0; k < 26; k++)
                {
                    for (int c = 2; c <= alp[k]; c++)//要除的分母
                    {
                        int temp = c;
                        for (int n = 2; n <= back&&temp > 1; n++)//分子
                        {
                            //防止溢位，邊乘邊約分
                            int g = gcd(temp, num[n]);
                            temp /= g;
                            num[n] /= g;
                        }
                    }
                }

                alp[j]++;//歸位

                //計算以每個小於str[i]的字母做替換的組合數
                LL result = 1;
                for (k = 2; k <= back; k++)
                    result *= num[k];
                ans += result;
            }

            alp[str[i] - 'a']--;//此字母已被計算完成
        }

        printf("%10lld\n", ans + 1);
    }


    return 0;
}
int gcd(int a, int b)
{
    while (a)
    {
        int temp = a;
        a = b%a;
        b = temp;
    }

    return b;
}