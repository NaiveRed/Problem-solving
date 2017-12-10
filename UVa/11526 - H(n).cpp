#include <cstdio>
#include <cmath>
typedef long long LL;

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int n, sqrt_n;
        scanf("%d", &n);
        sqrt_n = sqrt(n);

        LL sum = 0;

        for (int i = 1; i <= sqrt_n; i++)
        {
            int temp = n / i;
            int count = temp - n / (i + 1);
            sum += (LL)i * count + (temp == i ? 0 : temp); //避免重複計算
        }

        printf("%lld\n", sum);
    }

    return 0;
}
