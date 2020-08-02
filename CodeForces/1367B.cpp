#include <cstdio>

int main()
{
  int Case;
  scanf("%d", &Case);

  while (Case--)
  {
    int n, a, odd = 0, even = 0, count = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
      scanf("%d", &a);
      if (a & 1)
      {
        ++odd;
        if (!(i & 1))
          ++count;
      }
      else
        ++even;
    }

    if (odd != (n / 2))
      puts("-1");
    else if (!count)
      puts("0");
    else
      printf("%d\n", count);
  }

  return 0;
}