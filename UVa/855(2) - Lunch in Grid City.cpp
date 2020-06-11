#include <cstdio>
#include <algorithm>

int main()
{
  int T, F, x[50000], y[50000], ans_y, ans_x;
  scanf("%d", &T);
  while (T--)
  {
    scanf("%*d%*d%d", &F);
    for (int i = 0; i < F; ++i)
      scanf("%d%d", &y[i], &x[i]);
    std::sort(x, x + F);
    std::sort(y, y + F);

    ans_x = (F & 1) ? x[F / 2] : x[F / 2 - 1];
    ans_y = (F & 1) ? y[F / 2] : y[F / 2 - 1];

    printf("(Street: %d, Avenue: %d)\n", ans_y, ans_x);
  }

  return 0;
}