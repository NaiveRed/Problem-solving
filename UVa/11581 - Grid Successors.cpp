#include <cstdio>
#include <algorithm>

int main()
{
  bool flag[512] = {};
  int cases, g[25] = {}, new_g[25] = {};
  int *new_pg, *pg;
  scanf("%d", &cases);
  getchar();
  while (cases--)
  {
    new_pg = new_g, pg = g;
    std::fill(flag, flag + 512, false);
    getchar();
    for (int i = 1; i <= 3; ++i)
    {
      for (int j = 1; j <= 3; ++j)
        g[i * 5 + j] = getchar() - '0';
      getchar();
    }

    int count = 0;
    while (true)
    {
      // Encode
      int n = 0;
      for (int i = 1; i <= 3; ++i)
        for (int j = 1; j <= 3; ++j)
          n = (n << 1) + pg[i * 5 + j];

      if (flag[n] || !n)
        break;

      ++count;
      flag[n] = true;

      // Function f
      for (int i = 1; i <= 3; ++i)
        for (int j = 1; j <= 3; ++j)
        {
          int idx = i * 5 + j;
          new_pg[idx] = (pg[idx - 1] + pg[idx + 1] + pg[idx + 5] + pg[idx - 5]) & 1;
        }
      int *tmp = new_pg;
      new_pg = pg;
      pg = tmp;
    }

    printf("%d\n", count - 1);
  }

  return 0;
}