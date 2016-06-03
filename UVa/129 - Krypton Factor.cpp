/*
n 不是長度，是順序

ex.

3 2
ABA

4 2
B

5 2
BA

6 2
BAB
*/
#include<cstdio>

int count, n;
bool backtracking(int L, int idx);
int main()
{
    int l;
    while (scanf("%d%d", &n, &l) && n&&l)
    {
        count = 0;
        backtracking(l, 0);
    }

    return 0;
}
bool backtracking(int L, int idx)
{
    static int ans[81];

    if (count == n)
    {
        int f = 0, g = 0;
        for (int i = 1; i <= idx; i++, f++)
        {
            if (f == 4)
            {
                g++;
                if (g == 16)
                {
                    putchar('\n');
                    g = 0;
                }
                else
                    putchar(' ');
                f = 0;
            }

            putchar('A' + ans[i]);
        }

        printf("\n%d\n", idx);
        return true;
    }

    idx++;
    int max = idx >> 1, j;
    for (int i = 0; i < L; i++)
    {
        bool hard = true;
        ans[idx] = i;
        //從長度為 1 的後綴到長度為 目前長度/2 的字串一一比較其相鄰子字串，都不相同才為 hard
        for (int len = 1; len <= max; len++)
        {
            hard = false;
            for (j = 0; j < len; j++)
                if (ans[idx - j] != ans[idx - len - j])
                {
                hard = true;
                break;
                }

            if (!hard)
                break;
        }

        if (hard)
        {
            count++;
            if (backtracking(L, idx))
                return true;
        }
    }

    return false;
}