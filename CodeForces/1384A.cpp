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

void solve1()
{
  int n, a[105];
  scanf("%d", &n);
  for (int i = 0; i < n; ++i)
    scanf("%d", &a[i]);

  char prev_str[51] = {};
  fill(prev_str, prev_str + max(1, a[0]), 'a');
  puts(prev_str);
  for (int i = 1; i < n; ++i)
  {
    char str[51] = {};
    int len = max({1, a[i], a[i - 1]}), j;
    for (j = 0; j < a[i - 1]; ++j)
      str[j] = prev_str[j];
    for (; j < len; ++j)
      str[j] = prev_str[j] != '\0' ? ('a' + (prev_str[j] - 'a' + 1) % 26) : 'a';
    puts(str);
    memcpy(prev_str, str, len + 1);
  }
  if (a[n - 1])
    for (int j = 0; j < a[n - 1]; ++j)
      putchar(prev_str[j]);
  else
    putchar('a' + (prev_str[0] - 'a' + 1) % 26);
  putchar('\n');
}
void solve()
{
  int n, a;
  scanf("%d", &n);
  string s(51, 'x');
  puts(s.c_str());
  for (int i = 0; i < n; ++i)
  {
    scanf("%d", &a);
    s[a] ^= 1;
    puts(s.c_str());
  }
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
