#include <cstdio>
using namespace std;

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    int arr1[100005] = {}, arr2[100005] = {};
    for (int i = 0; i < n; ++i)
        scanf("%d", &arr1[i]);
    for (int i = 0; i < m; ++i)
        scanf("%d", &arr2[i]);

    int sum1 = arr1[0], sum2 = arr2[0];
    int a = 1, b = 1, count = 0;

    while (a < n && b < m)
    {
        if (sum1 < sum2)
            sum1 += arr1[a++];
        else if (sum1 > sum2)
            sum2 += arr2[b++];
        else
        {
            ++count;
            sum1 = arr1[a++];
            sum2 = arr2[b++];
        }
    }

    if (sum1)
        ++count;
    printf("%d\n", count);

    return 0;
}