#include <cstdio>

int main()
{
  int T, S, A, F, ans_s, ans_a;
  scanf("%d", &T);
  while (T--)
  {
    int grid_s[1001] = {}, grid_a[1001] = {};
    scanf("%d%d%d ", &S, &A, &F);

    for (int i = 0, y, x; i < F; ++i)
    {
      scanf("%d%d", &y, &x);
      ++grid_s[y];
      ++grid_a[x];
    }
    int median = (F & 1) ? (F / 2 + 1) : (F / 2);

    ans_s = ans_a = 1;
    for (int count = 0; count < median; ++ans_s)
      count += grid_s[ans_s];
    for (int count = 0; count < median; ++ans_a)
      count += grid_a[ans_a];

    printf("(Street: %d, Avenue: %d)\n", ans_s - 1, ans_a - 1);
  }

  return 0;
}