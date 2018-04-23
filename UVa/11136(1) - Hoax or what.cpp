#include <cstdio>
#include <cstring>
#include <vector>
#include <functional>
#include <queue>
#define N 1000001
using namespace std;

inline int read()
{
    int n = 0;
    char c;
    while ((c = getchar()) >= '0' && c <= '9')
        n = n * 10 + c - '0';
    return n;
}
int main()
{
    int n;

    static int used[N] = {};
    while (scanf("%d", &n) && n)
    {
        getchar();

        priority_queue<int, vector<int>, less<int>> urn_h;
        priority_queue<int, vector<int>, greater<int>> urn_l;
        long long sum = 0;

        for (int i = 0; i < n; ++i)
        {
            int k, bill;
            //scanf("%d", &k);
            k = read();
            for (int j = 0; j < k; ++j)
            {
                //scanf("%d", &bill);
                bill = read();
                urn_h.push(bill);
                urn_l.push(bill);
                ++used[bill]; //紀錄總數
            }

            int high, low;
            while (!used[urn_h.top()])
                urn_h.pop();

            high = urn_h.top();
            urn_h.pop();
            --used[high];

            while (!used[urn_l.top()])
                urn_l.pop();

            low = urn_l.top();
            urn_l.pop();
            --used[low];

            sum += high - low;
        }

        printf("%lld\n", sum);

        memset(used, 0, sizeof used);
    }

    return 0;
}
