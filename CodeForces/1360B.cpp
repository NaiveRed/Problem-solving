#include <cstdio>

inline int Input()
{
  char c;
  int n = 0;
  while ((c = getchar()) != EOF && c != '\n' && c != ' ')
    n = n * 10 + c - '0';

  return n;
}
int main()
{
  int t;
  scanf("%d", &t);
  getchar();
  while (t--)
  {
    int n, s, arr[1001] = {}, l = 2000, r = 0, ans = 2000;
    n = Input();
    //scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
      //scanf("%d", &s);
      s = Input();
      if (++arr[s] > 1)
      {
        ans = 0;
        if (i != n - 1)
          while (getchar() != '\n')
            ;
        break;
      }
      if (s > r)
        r = s;
      if (s < l)
        l = s;
    }

    if (ans)
      for (int i = l + 1, min = l; i <= r; ++i)
      {
        if (arr[i])
        {
          if (arr[i] > 1)
          {
            ans = 0;
            break;
          }

          if (i - min < ans)
            ans = i - min;
          min = i;
        }
      }
    printf("%d\n", ans);
  }

  return 0;
}
