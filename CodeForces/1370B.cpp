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
  int n, a;
  vector<pair<int, int>> odd, even;
  scanf("%d", &n);
  for (int i = 0; i < 2 * n; ++i)
  {
    scanf("%d", &a);
    if (a & 1)
      odd.push_back({i, a});
    else
      even.push_back({i, a});
  }
  if (odd.size() & 1)
  {
    odd.pop_back();
    even.pop_back();
  }
  else
  {
    if (odd.size())
    {
      odd.pop_back();
      odd.pop_back();
    }
    else
    {
      even.pop_back();
      even.pop_back();
    }
  }
  for (int i = 0, len = odd.size(); i < len; i += 2)
    printf("%d %d\n", odd[i].first + 1, odd[i + 1].first + 1);
  for (int i = 0, len = even.size(); i < len; i += 2)
    printf("%d %d\n", even[i].first + 1, even[i + 1].first + 1);
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
