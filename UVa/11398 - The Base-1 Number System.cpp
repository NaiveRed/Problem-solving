#include <cstdio>
#define N 1000

int main()
{
    char str[N];
    int count = 0, sum = 0, flag = -1;
    bool end = false;
    while (fgets(str, N, stdin) && str[0] != '~')
    {
        for (int i = 0; str[i] != '\n'; i++)
        {
            if (str[i] == '0')
                count++;
            else
            {
                if (count > 2)
                {
                    count -= 2;
                    sum <<= count;
                    if (flag)
                    {
                        int tmp = 0;
                        for (int j = count; j; j--)
                            tmp = (tmp << 1) + 1;
                        sum += tmp;
                    }
                }
                else if (count == 1)
                    flag = 1;
                else if (count == 2)
                    flag = 0;
                count = 0;

                if (str[i] == '#' && i && str[i - 1] == ' ')
                    end = true;
            }
        }

        if (end)
        {
            printf("%d\n", sum);
            end = false;
            sum = count = 0;
        }
    }

    return 0;
}