#include <bits/stdc++.h>
//#define DEBUG
#define MULTICASE
#define dbg(x) cerr << #x " = " << x << endl;
#define CASET         \
  int ___T;           \
  scanf("%d", &___T); \
  for (int _t = 1; _t <= ___T; ++_t)
using namespace std;


void solve()
{
  int n, ans = 0;
  scanf("%d", &n);
  if (n & 1)
    printf("%d\n", (n - 1) / 2);
  else
    printf("%d\n", n / 2);
}
int main()
{
#ifdef DEBUG
  freopen("problem.in", "r", stdin);
  freopen("problem.out", "w", stdout);
  clock_t _t_start = clock();
#endif

  // ios_base::sync_with_stdio(false);
  // cin.tie(0);

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
