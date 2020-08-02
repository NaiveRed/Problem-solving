#include <cstdio>

int main()
{

  unsigned int n;
  while (scanf("%u", &n) && n)
  {
    unsigned int a = 0, b = 0, i = 0, turn = 0;
    while (n)
    {
      unsigned int bit = n & 1;
      if (bit)
      {
        if (turn)
          b |= 1 << i;
        else
          a |= 1 << i;
        turn ^= 1;
      }

      ++i;
      n >>= 1;
    }

    printf("%u %u\n", a, b);
  }

  return 0;
}