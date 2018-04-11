#include <cstdio>
#define N 20000001
typedef long long LL;
int main()
{
    //SUM(MSLCM(n)) = [SUM(i*floor(n/i))]-1
    //i = 1 ~ n
    static LL ans[N] = {};
    for (int i = 2; i < N; ++i)
    {
        //處理在 MSLCM(j) 的 set 中出現的 i
        //j 為 i 的倍數
        for (int j = i; j < N; j += i)
            ans[j] += i;
        //MSLCM(n)
        ans[i] += ans[i - 1] + 1; //沒處理 1，要加上去
    }

    int n;
    while (scanf("%d", &n) && n)    
        printf("%lld\n", ans[n]);    

    return 0;
}