#include<cstdio>
#include<algorithm>
#define N 2703664

int factorial[N];

void solve();
int binary_search(int n);//找第一個等於 n 的，如沒有回傳 -1
int main()
{
    solve();

    int n, Case = 1;

    while (scanf("%d", &n) && n >= 0)
    {
        printf("Case %d: ", Case++);
        if (!n)
            puts("0!");
        else
        {
            int ans = binary_search(n);
            if (ans == -1)
                puts("Not possible.");
            else
                printf("%d!\n", ans);
        }
    }
    return 0;
}
void solve()
{
    std::fill(factorial, factorial + N, 1);
    factorial[0] = factorial[1] = 0;

    // 對 i (非階乘)做質因數分解後所需的質數個數
    for (int i = 2; i < N; i++)
    {
        if (factorial[i] == 1)//如不是質數，在前面就已經做過了
            for (int j = 2; j*i < N; j++)
                factorial[i*j] = factorial[i] + factorial[j];
    }

    //i! 所需的質數個數 
    for (int i = 2; i < N; i++)
        factorial[i] += factorial[i - 1];
}
int binary_search(int n)
{
    int left = 0, right = N - 1, mid = (left + right) / 2;
    while (left < right)
    {
        if (n <= factorial[mid])
            right = mid;
        else
            left = mid + 1;

        mid = (left + right) / 2;
    }

    return factorial[mid] == n ? mid : -1;
}