#include <cstdio>
#include <cstring>
#define N 22

int main()
{    
    char str[N];
    int T;
    scanf("%d ", &T);
    for (int t = 1; t <= T; ++t)
    {
        unsigned long long alp[26] = {}, sum = 1;

        fgets(str, N, stdin);
        int len = strlen(str) - 1;

        for (int i = 0; i < len; ++i)
        {
            ++alp[str[i] - 'A'];

            //邊乘邊除
            sum *= i + 1;
            if (alp[str[i] - 'A'] > 1)
                sum /= alp[str[i] - 'A'];
        }

        printf("Data set %d: %llu\n", t, sum);
    }
    return 0;
}