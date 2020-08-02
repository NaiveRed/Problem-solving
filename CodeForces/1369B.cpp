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
  int n, start = -1, no_pair_1 = -1;
  bool match_0 = false, match_1 = false, is_match = false;
  scanf("%d ", &n);

  for (int i = 0; i < n; ++i)
  {
    char c = getchar();
    if (start == -1)
    {
      if (c == '1')
        start = i;
      else
        putchar('0');
    }

    if (c == '1')
    {
      match_1 = true;
      if (match_0)
        match_0 = false;

      if (no_pair_1 == -1)
        no_pair_1 = i;
    }
    else if (match_1 && c == '0')
    {
      match_0 = true;
      no_pair_1 = -1;
      is_match = true;
    }
  }

  if (is_match)
    putchar('0');
  if (no_pair_1 >= 0)
    for (int i = no_pair_1; i < n; ++i)
      putchar('1');

  putchar('\n');
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
