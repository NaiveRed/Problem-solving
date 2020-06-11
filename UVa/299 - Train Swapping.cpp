#include <cstdio>

int main()
{
  int cases, L, arr[50];
  scanf("%d", &cases);
  for (int c = 0; c < cases; ++c)
  {
    scanf("%d", &L);
    for (int i = 0; i < L; ++i)
      scanf("%d", &arr[i]);

    int ans = 0, tmp;
    for (int i = 0; i < L; ++i)
      for (int j = 0; j < L - i - 1; ++j)
        if (arr[j] > arr[j + 1])
        {
          tmp = arr[j];
          arr[j] = arr[j + 1];
          arr[j + 1] = tmp;
          ++ans;
        }

    printf("Optimal train swapping takes %d swaps.\n", ans);
  }
  return 0;
}