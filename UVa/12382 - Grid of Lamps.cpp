#include <cstdio>
#include <algorithm>
#include <functional>
#define N 1000
using namespace std;

inline int input()
{
    int n = 0;
    char c;
    while ((c = getchar()) != '\n' && c != ' ')
        n = n * 10 + c - '0';
    return n;
}
int main()
{
    int T;
    int row[N] = {}, col[N] = {};
    scanf("%d", &T);
    while (T--)
    {
        int n, m;
        scanf("%d%d ", &n, &m);
        for (int i = 0; i < n; ++i)
            row[i] = input();
        //scanf("%d", &row[i]);

        for (int i = 0; i < m; ++i)
            col[i] = input();
        //scanf("%d", &col[i]);

        sort(col, col + m, greater<int>());

        int sum = 0;
        for (int r = 0; r < n; ++r)
        {

            for (int c = 0; c < m && col[c] && row[r]; ++c)
                if (col[c])
                {
                    --col[c];
                    --row[r];
                    ++sum;
                }

            //確保每次都先從還有缺的 col 開始相抵
            std::sort(col, col + m, greater<int>());

            //加上低估燈數
            sum += row[r];
        }

        //加上低估燈數
        for (int c = 0; c < m && col[c]; ++c)
            sum += col[c];

        printf("%d\n", sum);
    }

    return 0;
}