#include <cstdio>
#include <cstring>
#define N 1000002

inline int get_len(int n)
{
    int tmp = 10, res = 1;
    while (n >= tmp)
    {
        res++;
        tmp *= 10;
    }
    return res;
}
int main()
{
    char str[N];
    while (fgets(str, N, stdin))
    {
        if (str[0] == 'E')
            break;

        int x_next = strlen(str), idx = 1, x = -1;
        str[--x_next] = '\0';

        if (x_next == 1)
            x = str[0] - '0'; //x_0

        while (true)
        {
            if (x == x_next) //x_i==x_i+1
                break;
            idx++;
            x = x_next;
            x_next = get_len(x_next);
        }

        printf("%d\n", idx);
    }

    return 0;
}