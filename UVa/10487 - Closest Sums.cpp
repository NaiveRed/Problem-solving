#include<cstdio>
#include<algorithm>
#include<climits>
#define ABS(a) ((a)<0?(-(a)):(a))

int num[1000];
int binary_search(int n, int tar);
int main()
{
    int i;
    int n, Case = 0;
    while (scanf("%d", &n) && n)
    {
        printf("Case %d:\n", ++Case);

        for (i = 0; i < n; i++)
            scanf("%d", &num[i]);
        std::sort(num, num + n);

        int m, temp;
        scanf("%d", &m);
        for (int i = 0; i < m; i++)
        {
            scanf("%d", &temp);
            printf("Closest sum to %d is %d.\n", temp, binary_search(n, temp));
        }
    }

    return 0;
}
int binary_search(int n, int tar)
{
    int min = INT_MAX, ans;
    for (int i = 0; i < n - 1; i++)
    {
        int diff = tar - num[i], diff2, temp;
        int idx = std::lower_bound(num + i + 1, num + n, diff) - num;
        if (idx == n)//沒找到大於等於的
            idx = n - 1;

        diff2 = ABS(diff - num[idx]);//兩者之和與 tar 的差

        //判斷 num[idx] 和 num[idx-1] 哪個可使與 tar 的差距更小
        if (num[idx] > diff && (idx - 1) != i)
        {
            temp = ABS(diff - num[idx - 1]);
            if (temp < diff2)
            {
                idx--;
                diff2 = temp;
            }
        }
        
        //找出離 tar 最近的
        if (min > diff2)
        {
            min = diff2;
            ans = num[idx] + num[i];
        }
    }

    return ans;
}