// Need different numbers
#include <cstdio>
#include <cmath>

int main()
{

  int Case;
  scanf("%d", &Case);
  while (Case--)
  {
    int A, B, C;
    scanf("%d%d%d", &A, &B, &C);
    int limit = (int)sqrt((double)C);
    bool done = false;
    for (int i = -limit; i <= limit && !done; ++i)
      for (int j = -limit; j <= limit; ++j)
      {
        int k = A - i - j;
        if (i == j || i == k || j == k || k * i * j != B || i * i + j * j + k * k != C)
          continue;
        else
        {
          printf("%d %d %d\n", i, j, k);
          done = true;
          break;
        }
      }

    if (!done)
      puts("No solution.");
  }

  return 0;
}