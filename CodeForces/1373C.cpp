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
  getchar();          \
  for (int _t = 1; _t <= ___T; ++_t)
using namespace std;

void solve()
{
  char c;
  int cur = 0, init = 0, i = 0; // cur value after the pseudocode with init=0
  long long ans = 0;
  while ((c = getchar()) != '\n' && c != EOF)
  {
    cur = cur + ((c == '+') ? 1 : -1);
    ++i;
    if (cur + init < 0)
    {
      ans += i;
      ++init;
    }
  }
  ans += i; //Pass the whole string
  printf("%lld\n", ans);
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
