#include <cstdio>

int main()
{

  int Case;
  scanf("%d", &Case);
  while (Case--)
  {
    int i, d, k, c[21], count = 0, n = 0;
    scanf("%d", &i);
    for (int j = 0; j <= i; ++j)
      scanf("%d", &c[j]);
    scanf("%d%d", &d, &k);
    while (count < k)
    {
      count += d * (n + 1);
      ++n;
    }

    long long an = c[0], en = n;
    for (int j = 1; j <= i; ++j)
    {
      an += en * c[j];
      en *= n;
    }
    printf("%lld\n", an);
  }

  return 0;
}