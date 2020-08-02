#include <cstdio>
#include <algorithm>

int main()
{
  int Case;
  scanf("%d", &Case);

  while (Case--)
  {
    int n, x, sum = 0, left = 0, right = 0, a, ans = -1;
    scanf("%d%d", &n, &x);
    for (int i = 1; i <= n; ++i)
    {
      scanf("%d", &a);
      sum += a;
      if (a % x) // Non-multiple of x
      {
        if (!left)
          left = i;
        right = i;
      }
    }
    if (sum % x)
      ans = n;
    else if (left)
      ans = std::max(n - left, right - 1);

    printf("%d\n", ans);
  }

  return 0;
}