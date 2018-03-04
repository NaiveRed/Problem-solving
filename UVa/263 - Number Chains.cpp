#include <cstdio>
#include <algorithm>
#include <functional>
#include <unordered_map>
#include <set>
#define N 15
#define ORD(c) ((c) - '0')
#define CHR(n) ((n) + '0')

inline int to_num(int *n)
{
    int m = 0;
    for (int i = 0; n[i] != -1; i++)
        m = m * 10 + n[i];
    return m;
}
int main()
{
    //freopen("test.in", "r", stdin);
    //freopen("test.out", "w", stdout);
    //std::unordered_map<int, bool> num_map;
    int *num(new int[N]), *res(new int[N]);
    std::set<int> num_set;
    char c;
    while ((c = getchar()) != '0')
    {
        int len = 0, ans = 0;

        do
        {
            num[len++] = ORD(c);
        } while ((c = getchar()) != '\n');
        num[len] = -1;

        //for output
        printf("Original number was ");
        for (int i = 0; i < len; i++)
            putchar(CHR(num[i]));
        putchar('\n');

        while (true)
        {
            ans++;
            std::sort(num, num + len, std::greater<int>());

            int i, j;
            //num[],res[] 的個位數存在最左[0]

            //for output
            for (i = 0; i < len; i++) //bigger
                putchar(CHR(num[i]));
            putchar(' ');
            putchar('-');
            putchar(' ');
            bool zero = true;
            for (j = len - 1; j >= 0; j--) //smaller
            {
                if (zero && num[j])
                    zero = false;
                if (!zero)
                    putchar(CHR(num[j]));
            }
            if (zero) //number is zero
                putchar('0');

            //subtraction
            //i 為由大到小的數字的index，j 為由小到大的
            //for (i = len - 1, j = 0; i >= 0 && j < len; i--, j++)
            //res[j] = num[i] - num[j];
            for (i = len - 1; i >= 0; i--)
                res[len - 1 - i] = num[i] - num[len - 1 - i];

            for (i = 0; i < len; i++)
                if (res[i] < 0)
                {
                    res[i + 1]--; //借位
                    res[i] += 10; //補位
                }

            //record the new length and deal with leading zero
            for (i = len - 1; i >= 0; i--)
                if (res[i])
                {
                    len = i + 1;
                    res[len] = -1;
                    break;
                }
            if (i < 0) //number is zero
            {
                len = 1;
                res[0] = 0;
                res[len] = -1;
            }

            //swap res and num
            int *p = num;
            num = res;
            res = p;

            //for output
            putchar(' ');
            putchar('=');
            putchar(' ');
            for (i = len - 1; i >= 0; i--)
                putchar(CHR(num[i]));
            putchar('\n');

            //check the number appeared
            int tmp = to_num(num);
            /*if (num_map.count(tmp))
                break;
            else
                num_map[tmp] = true;*/
            if (num_set.count(tmp))
                break;
            else
                num_set.insert(tmp);
        }

        printf("Chain length %d\n\n", ans);
        //num_map.clear();
        num_set.clear();
    }

    delete[] num;
    delete[] res;
}