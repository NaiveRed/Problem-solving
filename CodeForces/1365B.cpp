#include <bits/stdc++.h>
//#define DEBUG
#define MULTICASE
#define IOS                    \
  ios::sync_with_stdio(false); \
  cin.tie(0);                  \
  cout.tie(0);
#define dbg(x) cerr << #x " = " << x << endl;
#define CASET         \
  int ___T;           \
  scanf("%d", &___T); \
  for (int _t = 1; _t <= ___T; ++_t)
using namespace std;

void solve()
{
  int n, b, a, prev;

  bool sorted = true, zero = false, one = false;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i)
  {
    scanf("%d", &a);
    if (i && prev > a)
      sorted = false;
    prev = a;
  }

  for (int i = 0; i < n; ++i)
  {
    scanf("%d", &b);

    if (b)
      one = true;
    else
      zero = true;
  }

  puts(((one && zero) || sorted) ? "Yes" : "No");
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
