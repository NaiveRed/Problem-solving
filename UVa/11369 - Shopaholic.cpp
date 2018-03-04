#include <cstdio>
#include <algorithm>
#define N 20001

inline int input()
{
    char c;
    int n = 0;
    while ((c = getchar()) != '\n' && c != ' ' && c != '\t' && c != EOF)
        n = n * 10 + c - '0';
    return n;
}
int main()
{
    int T;
    scanf("%d ", &T);
    while (T--)
    {
        int n, arr[N], ans = 0;
        n = input();
        for (int i = 0; i < n; i++)
            arr[i] = input();
        std::sort(arr, arr + n, [](const int &a, const int &b) -> bool { return a > b; }); //decreasing

        for (int i = 2; i < n; i += 3)
            ans += arr[i];
        printf("%d\n", ans);
    }

    return 0;
}