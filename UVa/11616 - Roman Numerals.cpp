#include <cstdio>
#define N 13

const int arr[N] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
const char roman[N][3] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
inline int ro2int(char c1, char c2, bool &flag)
{
    if (c1 == 'M')
        return 1000;
    if (c1 == 'D')
        return 500;
    if (c1 == 'L')
        return 50;
    if (c1 == 'V')
        return 5;
    if (c1 == 'C')
    {
        if (c2 == 'M')
        {
            flag = true;
            return 900;
        }
        if (c2 == 'D')
        {
            flag = true;
            return 400;
        }
        return 100;
    }
    if (c1 == 'X')
    {
        if (c2 == 'C')
        {
            flag = true;
            return 90;
        }
        if (c2 == 'L')
        {
            flag = true;
            return 40;
        }
        return 10;
    }
    if (c1 == 'I')
    {
        if (c2 == 'X')
        {
            flag = true;
            return 9;
        }
        if (c2 == 'V')
        {
            flag = true;
            return 4;
        }
        return 1;
    }
    return 0;
}
int main()
{
    char str[20];

    while (fgets(str, 20, stdin) && str[0] != '\n')
    {
        if (str[0] <= '9' && str[0] >= '0')
        {
            int n;
            sscanf(str, "%d", &n);
            //由大到小除
            for (int i = 0; i < N && n; ++i)
            {
                if (arr[i] > n)
                    continue;

                int k = n / arr[i]; //實際上應該只有 1 和 1000 會超過一次(1~3和1000,2000,3000)
                for (int j = 0; j < k; ++j)
                {
                    putchar(roman[i][0]);
                    if (roman[i][1])
                        putchar(roman[i][1]);
                }

                n %= arr[i];
            }

            putchar('\n');
        }
        else
        {
            int n = 0;
            for (int i = 0; str[i] != '\n'; ++i)
            {
                bool flag = false; //使否出現小的在前面
                int tmp = ro2int(str[i], str[i + 1], flag);
                if (flag) //兩字母代表一個數字的 e.g. IV
                    ++i;
                n += tmp;
            }
            printf("%d\n", n);
        }
    }

    return 0;
}