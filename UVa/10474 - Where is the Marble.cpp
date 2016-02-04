#include<cstdio>
#include<algorithm>

int num[10000];
int getNum();
int binary_search(int size, int n);
int main()
{
    int Case = 1;
    int N, Q;
    while (scanf("%d%d", &N, &Q) && N)
    {
        printf("CASE# %d:\n", Case++);

        for (int i = 0; i < N; i++)
            scanf("%d", &num[i]);

        std::sort(num, num + N);

        getchar();
        int q, ans;
        for (int i = 0; i < Q; i++)
        {
            q = getNum();

            ans = binary_search(N, q);
            if (num[ans] == q)
                printf("%d found at %d\n", q, ans + 1);
            else
                printf("%d not found\n", q);
        }
    }

    return 0;
}
int getNum()
{
    char c;
    int num = 0;
    while ((c = getchar()) != '\n')
        num = num * 10 + c - '0';

    return num;
}
int binary_search(int size, int n)
{
    int left = 0, right = size - 1;
    int mid = (left + right) / 2;

    while (left < right)
    {
        if (num[mid] > n)
            right = mid - 1;
        else if (num[mid] < n)
            left = mid + 1;
        else if (num[mid] == n)
            right = mid;

        mid = (left + right) / 2;
    }

    return mid;
}