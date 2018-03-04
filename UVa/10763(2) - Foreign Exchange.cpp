//AC but not the right answer. Can anyone provide a case that can hack this code?
#include <cstdio>
#include <cstring>
#include <unordered_map>
#define N 500001

inline int get_num()
{
    int n = 0;
    char c;
    while ((c = getchar()) != '\n' && c != ' ')
        n = n * 10 + c - '0';
    return n;
}
int main()
{
    //freopen("test.out", "w", stdout);
    int n, arr[2][N] = {};
    std::unordered_map<int, int> map;

    while (scanf("%d", &n) && n)
    {
        getchar();
        int a, b, idx = -1; //從 0 開始編號
        
        int max = n;
        bool ans = (n & 1) ? false : true; //奇數不可能可以配對
        while (n--)
        {
            a = get_num();
            b = get_num();
            //scanf("%d%d", &a, &b);
            if (ans)
            {
                if (!map.count(a))
                    map[a] = ++idx;
                if (!map.count(b))
                    map[b] = ++idx;

                if (idx + 1 > max)
                {
                    ans = false;
                    continue;
                }

                a = map[a];
                b = map[b];

                if (a > b) //大 -> 小
                {
                    arr[0][a]++;
                    arr[1][b]++;
                }
                else //小 -> 大
                {
                    arr[0][b]--;
                    arr[1][a]--;
                }
            }
        }

        if (ans)
        {
            for (int i = 0; i <= idx; i++)
                if (arr[0][i] || arr[1][i])
                {
                    ans = false;
                    break;
                }
        }

        puts(ans ? "YES" : "NO");

        map.clear();
        memset(arr[0], 0, sizeof(int) * (idx + 1));
        memset(arr[1], 0, sizeof(int) * (idx + 1));
    }

    return 0;
}
