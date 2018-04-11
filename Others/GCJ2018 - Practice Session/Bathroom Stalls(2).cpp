#include <cstdio>
typedef long long LL;

int main()
{
    int T;
    scanf("%d", &T);

    for (int t = 1; t <= T; ++t)
    {
        LL k, n;
        scanf("%lld%lld", &n, &k);

        LL even[2] = {}, odd[2] = {};
        if (n & 1)
        {
            odd[0] = n;
            odd[1] = 1;
        }
        else
        {
            even[0] = n;
            even[1] = 1;
        }

        LL count = 0, row = 1;
        for (; count + row < k; row <<= 1) //找出 k 在哪一層
        {
            count += row;

            //計算該層的奇數和偶數(只會有兩種)的個數
            if (even[0] > odd[0])
            {
                even[0] >>= 1;
                if (even[0] & 1)
                {
                    LL tmp = odd[1];
                    odd[0] = even[0];
                    odd[1] = even[1];
                    --even[0];
                    even[1] += (tmp << 1);
                }
                else
                {
                    odd[0] = even[0] - 1;
                    odd[1] = (odd[1] << 1) + even[1];
                }
            }
            else //odd>even
            {
                odd[0] >>= 1;
                if (odd[0] & 1)
                {
                    even[0] = odd[0] - 1;
                    odd[1] = (odd[1] << 1) + even[1];
                }
                else
                {
                    LL tmp = even[1];
                    even[0] = odd[0];
                    even[1] += (odd[1] << 1);

                    --odd[0];
                    odd[1] = tmp;
                }
            }

            /*printf("%lld %lld\n", even[0], even[1]);
            printf("%lld %lld\n", odd[0], odd[1]);
            puts("");*/
        }
        
        //從區間大的開始放
        if (even[0] > odd[0])
        {
            if (k - count <= even[1])
                printf("Case #%d: %lld %lld\n", t, even[0] >> 1, (even[0] >> 1) - 1);
            else
                printf("Case #%d: %lld %lld\n", t, odd[0] >> 1, odd[0] >> 1);
        }
        else
        {
            if (k - count <= odd[1])
                printf("Case #%d: %lld %lld\n", t, odd[0] >> 1, odd[0] >> 1);
            else
                printf("Case #%d: %lld %lld\n", t, even[0] >> 1, (even[0] >> 1) - 1);
        }
    }

    return 0;
}