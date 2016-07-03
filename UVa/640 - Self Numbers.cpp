#include<cstdio>
#define N 1000001
int main()
{
    bool ans[N] = {};
    for (int i = 1; i < 999999; i++)
    {
        int sum = i, temp = i;
        while (temp)
        {
            sum += temp % 10;
            temp /= 10;
        }

        if (sum < N)
            ans[sum] = true;
    }

    for (int i = 1; i < N; i++)
        if (!ans[i])
            printf("%d\n", i);

    return 0;
}