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
  long long l, r, m, diff;
  scanf("%lld%lld%lld", &l, &r, &m);
  diff = r - l;
  long long a = l, b, c, m_mod_a;
  while (a <= r)
  {
    m_mod_a = m % a;
    if (m_mod_a <= diff)
    {
      b = r;
      c = r - m_mod_a;
      if (m - b + c != 0)
        break;
    }

    if (a - m_mod_a <= diff)
    {
      b = l;
      c = l + (a - m_mod_a);
      break;
    }

    ++a;
  }
  printf("%lld %lld %lld\n", a, b, c);
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
