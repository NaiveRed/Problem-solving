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

int n, k, arr[200100], w[200100];
void solve()
{
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; ++i)
    scanf("%d", &arr[i]);
  for (int i = 0; i < k; ++i)
    scanf("%d", &w[i]);
  sort(arr, arr + n);
  sort(w, w + k);

  int a_ta = n - k - 1;
  long long ans = 0;
  for (int i = 0; i < k; ++i)
    ans += arr[n - i - 1] + (w[i] == 1 ? arr[n - i - 1] : 0);
  for (int i = 0; i < k; ++i)
  {
    if (w[i] != 1)
    {
      a_ta -= w[i] - 2;
      ans += arr[a_ta--];
    }
  }
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
