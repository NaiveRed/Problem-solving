#include <cstdio>
#include <cstdlib>
#define N 500000
typedef long long LL;

inline int getNum()
{
  char c;
  int n = 0;
  while ((c = getchar()) != '\n')
    n = n * 10 + c - '0';
  return n;
}
//iterative version
LL merge_sort(int *p_num, int *p_sortArr, int len)
{
  LL swap = 0;

  for (int seg = 1; seg < len; seg <<= 1) //一半子序列的長度
  {
    int m = seg << 1; //子序列的長度
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
          swap += end1 - s1 + 1; //次數為左子序列剩下的還沒排序的數字
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

  return swap;
}
int main()
{
  static int p_sortArr[N];
  static int p_num[N];

  int n;

  while (n = getNum())
  {
    for (int i = 0; i < n; i++)
      p_num[i] = getNum();
    printf("%lld\n", merge_sort(p_num, p_sortArr, n));
  }

  return 0;
}
