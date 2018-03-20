#include <cstdio>
#include <cstring>
#include <unordered_map>
#include <string>
using namespace std;

int main()
{
    int m, n;
    unordered_map<string, int> point;
    scanf("%d%d", &m, &n);
    char str[100];
    int pt;
    for (int i = 0; i < m; ++i)
    {
        scanf("%s %d", str, &pt);
        point[string(str)] = pt;
    }
    for (int i = 0; i < n; ++i)
    {
        int sum = 0;
        while (true)
        {
            scanf("%s", str);
            if (str[0] == '.')
            {
                printf("%d\n", sum);
                break;
            }
            string s(str);
            if (point.count(s))
                sum += point[s];
        }
    }

    return 0;
}