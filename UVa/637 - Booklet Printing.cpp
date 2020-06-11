/*Find the pattern:
page: front/back
1: 8,1/2,7
2: 6,3/4,5
...
if n > 4 blank will only show at position 8,6,7,5.
*/
#include <cstdio>
#include <cmath>

int main()
{
  int n;

  while (scanf("%d", &n) && n)
  {
    if (n == 1)
    {
      puts("Printing order for 1 pages:\nSheet 1, front: Blank, 1");
      continue;
    }
    int blank = (4 - n % 4) % 4;
    int sheet = (int)ceil((float)n / 4);
    printf("Printing order for %d pages:\n", n);
    for (int i = 1, p = 1; i <= sheet; ++i, p += 2)
    {
      if (blank)
      {
        printf("Sheet %d, front: Blank, %d\n", i, p);
        --blank;
      }
      else
        printf("Sheet %d, front: %d, %d\n", i, n--, p);        

      if (blank)
      {
        printf("Sheet %d, back : %d, Blank\n", i, p + 1);
        --blank;
      }
      else
        printf("Sheet %d, back : %d, %d\n", i, p + 1, n--);
    }
  }

  return 0;
}