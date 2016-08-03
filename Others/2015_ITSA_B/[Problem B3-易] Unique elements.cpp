#include<cstdio>
#include<algorithm>
#include<map>
using namespace std;

int main()
{
    int n,ans[1001], i;
    map<int, int> m;
    while (scanf("%d", &n) != EOF)
    {
        int count = 0, temp;
        m.clear();
        for (i = 0; i < n; i++)
        {
            scanf("%d", &temp);
            m[temp]++;
        }
        
        for (map<int, int>::iterator it = m.begin(); it != m.end(); it++)
            if (it->second == 1)
                ans[count++] = it->first;
        if (!count)
            puts("N/A");
        else
        {
            sort(ans, ans + count);
            printf("%d", ans[0]);
            for (i = 1; i < count; i++)
                printf(" %d", ans[i]);
            putchar('\n');
        }
    }

    return 0;
}