//iterative version
#include <cstdio>
#include <cstring>
#define N 100000
#define LEN 1000000

int *p_sortArr = new int[N]();
int *p_num = new int[N]();
char str[LEN];
int merge_sort(int len)
{
    int moves = 0;

    for (int seg = 1; seg < len; seg <<= 1) //一半子序列的長度
    {
        int m = seg << 1; //子序列的長度(左+右)
        for (int start = 0; start < len; start += m)
        {
            int left = start;
            int mid = start + seg - 1 > len - 1 ? len - 1 : start + seg - 1;
            int right = start + m - 1 > len - 1 ? len - 1 : start + m - 1;

            int s1 = left, end1 = mid;
            int s2 = mid + 1, end2 = right;

            int idx = left;
            while (s1 <= end1 && s2 <= end2)
            {
                if (p_num[s1] <= p_num[s2])
                    p_sortArr[idx++] = p_num[s1++];
                else
                {
                    p_sortArr[idx++] = p_num[s2++];
                    moves += end1 - s1 + 1;
                }
            }
            while (s1 <= end1)
                p_sortArr[idx++] = p_num[s1++];
            while (s2 <= end2)
                p_sortArr[idx++] = p_num[s2++];
        }

        //將原本的 ptr 指向排序好的
        int *temp = p_num;
        p_num = p_sortArr;
        p_sortArr = temp;
    }

    return moves;
}
int read()
{
    fgets(str, LEN, stdin);
    int n = 0, i;
    for (i = 0; str[i] != ' ' && str[i] != '\n'; ++i)
        n = n * 10 + str[i] - '0';

    for (int k = 0; k < n; ++k)
        for (++i; str[i] != ' ' && str[i] != '\n'; ++i)
            p_num[k] = p_num[k] * 10 + str[i] - '0';

    return n;
}
int main()
{
    int n;
    while ((n = read()) != 0)
    {
        puts((merge_sort(n) & 1) ? "Marcelo" : "Carlos");
        memset(p_num, 0, sizeof(int) * n);
        memset(p_sortArr, 0, sizeof(int) * n);
    }

    delete[] p_sortArr;
    delete[] p_num;
    return 0;
}