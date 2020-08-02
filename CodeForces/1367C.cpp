#include <cstdio>

int main()
{
  int Case, arr[200005];
  scanf("%d", &Case);

  while (Case--)
  {
    int n, k, ans = 0;
    scanf("%d%d ", &n, &k);
    for (int i = 0; i < n; ++i)
      arr[i] = getchar() - '0';

    getchar();

    int dis = k;
    for (int i = 0; i < n; ++i)
    {
      if (!arr[i])
      {
        if (++dis == 2 * k + 1)
        {
          ++ans;
          dis = k;
        }
      }
      else
        dis = 0;
    }

    if (dis > k)
      ++ans;

    printf("%d\n", ans);
  }

  return 0;
}