#include <cstdio>
#include <algorithm>
int arr[50000];
int low_b(int n, int h)
{
    int l = 0, r = n;
    while (l < r)
    {
        int mid = (l + r) >> 1;
        if (h < arr[mid])
            l = mid + 1;
        else
            r = mid;
    }
    return l;
}
int up_b(int n, int h)
{
    int l = 0, r = n;
    while (l < r)
    {
        int mid = (l + r) >> 1;
        if (h >= arr[mid])
            l = mid + 1; //要找大於他的
        else
            r = mid;
    }
    return l;
}
int main()
{    
    int n, q, h;
    scanf("%d ", &n);
    //輸入時已排序
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    scanf("%d", &q);
    for (int i = 0; i < q; i++)
    {
        scanf("%d", &h);

        int low = std::lower_bound(arr, arr + n, h) - arr;
        int up = std::upper_bound(arr, arr + n, h) - arr;
        //int low = low_b(n, h); //找第一個大於等於的
        //int up = up_b(n, h);   //找第一個大於的

        if (low) //有小於他的
            printf("%d", arr[low - 1]);
        else
            putchar('X');

        if (up != n) //有大於他的
            printf(" %d\n", arr[up]);
        else
            puts(" X");
    }

    return 0;
}