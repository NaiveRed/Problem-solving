#include <cstdio>
#include <algorithm>

int main()
{
  int Case;
  bool dp[1001] = {true};
  scanf("%d", &Case);
  while (Case--)
  {
    int n, p, bars[20];
    scanf("%d%d", &n, &p);
    for (int i = 0; i < p; ++i)
      scanf("%d", &bars[i]);
    std::fill(dp + 1, dp + n + 1, false);

    for (int i = 0; i < p; ++i)
      for (int len = n; len >= bars[i]; --len)
        dp[len] |= dp[len - bars[i]];

    puts(dp[n] ? "YES" : "NO");
  }

  return 0;
}