#include <bits/stdc++.h>
//#define DEBUG
#define MULTICASE
#define dbg(x) cerr << #x " = " << x << endl;
#define CASET         \
  int ___T;           \
  scanf("%d", &___T); \
  for (int _t = 1; _t <= ___T; ++_t)
using namespace std;

inline bool check_p(int n)
{
  for (int i = 3; i * i <= n; ++i)
    if (n % i == 0)
      return false;
  return true;
}
void solve()
{
  int n, a, win = 0;

  scanf("%d", &n);
  if (n == 1)
    win = 1;
  else if (n > 2 && n % 2 == 0)
  {
    if ((n & (n - 1)) == 0) // check the power of 2
      win = 1;
    else if (n % 4 != 0 && check_p(n / 2))
      win = 1;
  }

  if (win)
    puts("FastestFinger");
  else
    puts("Ashishgup");
}
int main()
{
#ifdef DEBUG
  freopen("problem.in", "r", stdin);
  freopen("problem.out", "w", stdout);
  clock_t _t_start = clock();
#endif

#ifdef MULTICASE
  CASET
  {
    solve();
  }
#else
  {
    solve();
  }
#endif

#ifdef DEBUG
  fprintf(stderr, "\nRuntime: %.10f s\n", (double)(clock() - _t_start) / CLOCKS_PER_SEC);
#endif
  return 0;
}
