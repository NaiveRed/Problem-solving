#include <cstdio>

int main()
{
  int t, n, arr[5000];
  scanf("%d", &t);
  while (t--)
  {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
      scanf("%d", &arr[i]);
    int ans = 0;
    for (int i = 1; i < n; ++i)
      for (int j = 0; j < i; ++j)
        if (arr[i] >= arr[j])
          ++ans;

    printf("%d\n", ans);
  }

  return 0;
}