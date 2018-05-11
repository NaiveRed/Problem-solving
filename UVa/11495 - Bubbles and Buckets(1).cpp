//recursive version
#include <cstdio>
#include <cstring>
#define N 100000
#define LEN 1000000

int arr[N];
int moves;
char str[LEN];
void merge(int L, int M, int R)
{
    static int sort_arr[N];

    int idx = L;
    int s1 = L, s2 = M + 1; //left/right
    while (s1 <= M && s2 <= R)
    {
        if (arr[s1] < arr[s2])
            sort_arr[idx++] = arr[s1++];
        else
        {
            sort_arr[idx++] = arr[s2++];
            moves += M - s1 + 1; //移動的位數: 左序列剩餘為排列的數字
        }
    }

    //[L, M] 剩餘未排進去的
    while (s1 <= M)
        sort_arr[idx++] = arr[s1++];

    //[M+1, R] 剩餘未排進去的
    while (s2 <= R)
        sort_arr[idx++] = arr[s2++];

    for (int i = L; i <= R; ++i)
        arr[i] = sort_arr[i];
}
void merge_sort(int L, int R)
{
    if (R - L + 1 < 2)
        return;

    int M = (R + L) >> 1;
    merge_sort(L, M);
    merge_sort(M + 1, R);
    merge(L, M, R);
}
int read()
{
    fgets(str, LEN, stdin);
    int n = 0, i;
    for (i = 0; str[i] != ' ' && str[i] != '\n'; ++i)
        n = n * 10 + str[i] - '0';

    for (int k = 0; k < n; ++k)
        for (++i; str[i] != ' ' && str[i] != '\n'; ++i)
            arr[k] = arr[k] * 10 + str[i] - '0';

    return n;
}
int main()
{
    int n;
    while ((n = read()) != 0)
    {
        merge_sort(0, n - 1);
        puts((moves & 1) ? "Marcelo" : "Carlos");
        moves = 0;
        memset(arr, 0, sizeof(int) * n);
    }

    return 0;
}