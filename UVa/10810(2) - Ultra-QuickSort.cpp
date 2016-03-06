#include<cstdio>
#define N 500000

int num[N];
inline int getNum();
void merge_sort(int left, int right, long long& swap);//recursive version
int main()
{
    int n;

    while (n = getNum())
    {
        for (int i = 0; i < n; i++)
            num[i] = getNum();
        long long ans = 0;
        merge_sort(0, n - 1, ans);
        printf("%lld\n", ans);
    }

    return 0;
}
inline int getNum()
{
    char c;
    int n = 0;
    while ((c = getchar()) != '\n')
        n = n * 10 + c - '0';
    return n;
}
void merge_sort(int left, int right, long long& swap)
{
    static int sortArr[N];
    if (left == right)
        return;

    int mid = (left + right) >> 1;
    int s1 = left, end1 = mid;
    int s2 = mid + 1, end2 = right;
    merge_sort(s1, end1, swap);
    merge_sort(s2, end2, swap);

    int idx = left;
    while (s1 <= end1&&s2 <= end2)
    {
        if (num[s1] <= num[s2])
            sortArr[idx++] = num[s1++];
        else
        {
            sortArr[idx++] = num[s2++];
            swap += end1 - s1 + 1;//次數為左子序列剩下的還沒排序的數字
        }
    }
    while (s1 <= end1)
        sortArr[idx++] = num[s1++];
    while (s2 <= end2)
        sortArr[idx++] = num[s2++];
    
    //把排序好的數字 assign 回去
    for (int i = left; i <= right; i++)
        num[i] = sortArr[i];
}