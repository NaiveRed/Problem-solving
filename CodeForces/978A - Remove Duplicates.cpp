#include <cstdio>

int main()
{
    int n, arr[50], ans[50];
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%d", arr + i);
    bool flag[1001] = {};

    int idx = 0;
    for (int i = n - 1; i >= 0; --i)
        if (!flag[arr[i]])
        {
            ans[idx++] = arr[i];
            flag[arr[i]] = true;
        }

    printf("%d\n", idx);
    for (--idx; idx; --idx)
        printf("%d ", ans[idx]);
    printf("%d\n", ans[0]);

    return 0;
}