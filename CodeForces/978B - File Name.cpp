#include <cstdio>

int main()
{
    int n;
    scanf("%d ", &n);
    int count = 0, reduce = 0;
    for (int i = 0; i < n; ++i)
    {
        char c = getchar();
        if (c == 'x')
        {
            ++count;
            if (count == 3)
            {
                --count;
                ++reduce;
            }
        }
        else
            count = 0;
    }

    printf("%d\n", reduce);

    return 0;
}
