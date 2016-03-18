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
        if (idx == n)//�S���j�󵥩�
            idx = n - 1;

        diff2 = ABS(diff - num[idx]);//��̤��M�P tar ���t

        //�P�_ num[idx] �M num[idx-1] ���ӥi�ϻP tar ���t�Z��p
        if (num[idx] > diff && (idx - 1) != i)
        {
            temp = ABS(diff - num[idx - 1]);
            if (temp < diff2)
            {
                idx--;
                diff2 = temp;
            }
        }
        
        //��X�� tar �̪�
        if (min > diff2)
        {
            min = diff2;
            ans = num[idx] + num[i];
        }
    }

    return ans;
}