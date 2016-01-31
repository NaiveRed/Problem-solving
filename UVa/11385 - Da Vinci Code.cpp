#include<cstdio>
#include<cstring>
#define M 46

int fib[M] = { 1, 1 };

int search(int n);//binary search
int main()
{
    //fibonacci
    int i;
    for (i = 2; i < M; i++)
        fib[i] = fib[i - 1] + fib[i - 2];

    int Case;
    scanf("%d", &Case);

    int num[100];
    char str[101], ans[101];
    while (Case--)
    {
        memset(ans, NULL, 101);
        int N;
        scanf("%d", &N);

        for (i = 0; i < N; i++)
            scanf("%d", &num[i]);

        getchar();
        gets(str);
        int len = strlen(str), j;
        for (i = 0, j = 0; j < N&&i < len; i++)
        {
            if (str[i] <= 'Z'&&str[i] >= 'A')
            {
                int k = search(num[j]);
                if (k != -1)
                    ans[k - 1] = str[i];

                j++;
            }
        }

        //fill space
        bool flag = false;
        for (i = 100; i >= 0; i--)
            if (ans[i] && !flag)
                flag = true;
            else if (!ans[i] && flag)
                ans[i] = ' ';

        puts(ans);
    }

    return 0;
}
int search(int n)
{
    int left = 1, right = M - 1;
    int mid;

    while (left <= right)
    {
        mid = (left + right) / 2;

        if (fib[mid] < n)
            left = mid + 1;
        else if (fib[mid] > n)
            right = mid - 1;
        else
            return mid;
    }

    return -1;
}