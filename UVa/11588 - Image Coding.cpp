#include <cstdio>

int main()
{
  int cases, R, C, M, N;
  char image[25];
  scanf("%d", &cases);
  for (int k = 1; k <= cases; ++k)
  {
    int max = 0, table[26] = {};
    scanf("%d%d%d%d ", &R, &C, &M, &N);
    for (int r = 0; r < R; ++r)
    {
      fgets(image, 25, stdin);
      for (int c = 0; c < C; ++c)
      {
        int n = image[c] - 'A';
        if (++table[n] > max)
          max = table[n];
      }
    }

    int bytes = 0;
    for (int i = 0; i < 26; ++i)
      bytes += table[i] * (table[i] == max ? M : N);
    printf("Case %d: %d\n", k, bytes);
  }

  return 0;
}