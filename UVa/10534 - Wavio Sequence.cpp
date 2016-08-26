#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
    int n, num[10000], lis[10000], lds[10000];
    vector<int> v;
    while (scanf("%d", &n) != EOF)
    {
        int i;
        for (i = 0; i < n; i++)
            scanf("%d", &num[i]);

        v.clear();
        int size = 1;
        v.push_back(num[0]);
        lis[0] = 1;
        for (i = 1; i < n; i++)
        {
            if (num[i] > v.back())
            {
                v.push_back(num[i]);
                lis[i] = ++size;
            }
            else
            {
                int temp = lower_bound(v.begin(), v.end(), num[i]) - v.begin();
                v[temp] = num[i];
                lis[i] = temp + 1;
            }
        }

        v.clear();
        size = 1;
        v.push_back(num[n - 1]);
        lds[n - 1] = 1;
        for (i = n - 2; i >= 0; i--)
        {
            if (num[i] > v.back())
            {
                v.push_back(num[i]);
                lds[i] = ++size;
            }
            else
            {
                int temp = lower_bound(v.begin(), v.end(), num[i]) - v.begin();
                v[temp] = num[i];
                lds[i] = temp + 1;
            }
        }

        /*for (i = 0; i < n; i++)
            printf("%d ", lis[i]);
        putchar('\n');
        for (i = 0; i < n; i++)
            printf("%d ", lds[i]);*/

        int max = 0;
        for (i = 0; i < n; i++)
        {
            int temp = min(lis[i], lds[i]);
            if (max < temp)
                max = temp;
        }

        printf("%d\n", max * 2 - 1);
    }

    return 0;
}