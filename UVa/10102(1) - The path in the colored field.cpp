#include<cstdio>
#include<utility>
#include<algorithm>
#include<cmath>
#define N 10000
using namespace std;
typedef pair<int, int> Pair;

inline int dir(Pair& a, Pair& b);
inline bool cmp(const Pair& a, const Pair& b){ return a.second < b.second; }
int main()
{
    int n, i, j;
    Pair one[N], three[N];
    while (scanf("%d", &n) != EOF)
    {
        getchar();
        int s = 0, t = 0;
        char c;
        for (i = 1; i <= n; i++)
        {
            for (j = 1; j <= n; j++)
            {
                c = getchar();
                if (c == '1')
                    one[s].first = i, one[s++].second = j;
                else if (c == '3')
                    three[t].first = i, three[t++].second = j;
            }
            getchar();
        }

        int max = 0;
        sort(three, three + t, cmp);
        for (i = 0; i < s; i++)
        {
            //二分搜找大於等於 one[i].second 的 three[]
            int idx = lower_bound(three, three + t, one[i], cmp) - three, d = 1e9;

            //往右找
            for (j = idx; j < t; j++)
            {
                if (one[i].second + d < three[j].second)
                    break;

                int temp = dir(three[j], one[i]);
                if (temp < d)
                    d = temp;
            }

            //往左找
            for (j = idx - 1; j >= 0; j--)
            {
                if (one[i].second - d > three[j].second)
                    break;

                int temp = dir(three[j], one[i]);
                if (temp < d)
                    d = temp;
            }

            if (d > max)
                max = d;
        }

        printf("%d\n", max);
    }


    return 0;
}
int dir(Pair& a, Pair& b)
{
    return abs(a.first - b.first) + abs(a.second - b.second);
}