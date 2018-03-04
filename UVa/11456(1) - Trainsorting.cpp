//LIS: O(NlogL)
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int Case, train[4000];
    vector<int> lis;
    scanf("%d", &Case);
    while (Case--)
    {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; ++i)
        {
            scanf("%d", &train[i + n]);
            train[n - i - 1] = train[i + n];
        }

        if (n)
            lis.push_back(train[0]);

        for (int i = 1; i < (n << 1); ++i)
        {
            if (train[i] > lis.back())
                lis.push_back(train[i]);
            else
                *(lower_bound(lis.begin(), lis.end(), train[i])) = train[i];
        }

        printf("%d\n", lis.size());
        lis.clear();
    }

    return 0;
}