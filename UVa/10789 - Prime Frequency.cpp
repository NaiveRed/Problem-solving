
#include <cstdio>
#include <cmath>
#define N 2001

int main()
{            
    bool sieve[N] = {true, true};
    int _sqrt = sqrt(N);
    for (int i = 2; i < _sqrt; i++)
    {
        if (!sieve[i])
            for (int j = i + i; j < N; j += i)
                sieve[j] = true;
    }

    int T;
    char str[N + 1];
    scanf("%d ", &T);
    for (int t = 1; t <= T; t++)
    {
        int count[100] = {}; //'0' = 48, 'z' = 122
        bool empty = true;
        fgets(str, N + 1, stdin);

        for (int i = 0; str[i] != '\n'; i++)
            count[str[i] - '0']++;
        printf("Case %d: ", t);
        for (int i = 0; i < 100; i++)
            if (!sieve[count[i]])
            {
                putchar('0' + i);
                empty = false;
            }

        puts(empty ? "empty" : "");
    }
    return 0;
}