#include <cstdio>
#include <cmath>
#define N 32768

inline int get_num()
{
    int n = 0;
    char c;
    while ((c = getchar()) != '\n' && c != ' ')
        n = n * 10 + c - '0';
    return n;
}
inline int gcd(int a, int b)
{
    while (b)
    {
        int tmp = a % b;
        a = b;
        b = tmp;
    }
    return a;
}
int main()
{
    /*bool not_prime[N] = {true, true};
    int sqrt_n = sqrt(N);
    for (int i = 2; i <= sqrt_n; i++)
    {
        if (!not_prime[i])
            for (int j = i + i; j < N; j += i)
                not_prime[j] = true;
    }*/

    int n, num[50];
    while (scanf("%d ", &n) && n)
    {
        for (int i = 0; i < n; i++)
            num[i] = get_num();

        int count = 0;
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
            {
                /*
                //多了一些判斷但時間沒有減少
                if (!(num[i] & 1) && !(num[j] & 1) ) //都偶數
                    continue;
                if (num[i] > num[j])
                    big = num[i], small = num[j];
                else
                    big = num[j], small = num[i];
                if (!not_prime[big] || big % small == 1)
                    count++;
                */

                if (gcd(num[i], num[j]) == 1)
                    count++;
            }

        /*
        x = ans1
        6/x = (幾對互質)/(總共幾對)
        x = 6 * (總共幾對) / (幾對互質)
        */
        if (count)
            printf("%.6lf\n", sqrt((double)6 * (n * (n - 1) / 2) / count));
        else
            puts("No estimate for this data set.");
    }

    return 0;
}