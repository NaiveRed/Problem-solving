#include <cstdio>
#define DEBUG

class Solution
{
public:
  int arrangeCoins(int n)
  {
    int left = 1, right = n;
    while (left <= right)
    {
      int mid = left + (right - left) / 2;
      long long coin = (long long)mid * (mid + 1) / 2;
      if (coin <= n)
        left = mid + 1;
      else
        right = mid - 1;
    }
    return right;
  }
};

int main()
{
#ifdef DEBUG
  freopen("problem.in", "r", stdin);
  freopen("problem.out", "w", stdout);
#endif

  Solution solution;
  int n;
  while (scanf("%d", &n) != EOF)
    printf("%d\n", solution.arrangeCoins(n));

  return 0;
}