#include <cstdio>
//#include <unordered_set>
//using namespace std;

int arr[1000000];
inline int read()
{
    int n = 0;
    char str[30];
    fgets(str, 30, stdin);
    for (int i = 0; str[i] != '\n'; ++i)
        n = n * 10 + str[i] - '0';

    return n;
}
/*int solve(int n, int m)
{
    int ans = 0;
    unordered_set<int> S;
    for (int i = 0; i < n; ++i)
        S.insert(read());
    for (int i = 0; i < m; ++i)
        if (S.count(read()))
            ++ans;
    return ans;
}*/
int solve(int n, int m)
{
    for (int i = 0; i < n; ++i)
        arr[i] = read();

    int ans = 0;
    for (int i = 0, idx = 0; i < m; ++i)
    {
        int tmp = read();

        while (idx < n && tmp > arr[idx])
            ++idx;

        if (idx == n)
            continue;

        if (tmp == arr[idx])
        {
            ++idx;
            ++ans;
        }
    }

    return ans;
}
int main()
{
    //freopen("test.out", "w", stdout);
    //freopen("test.in","r",stdin);
    int n, m;
    while (scanf("%d%d ", &n, &m) && (n || m))
        printf("%d\n", solve(n, m));

    return 0;
}