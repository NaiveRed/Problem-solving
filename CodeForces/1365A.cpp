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
inline int Input()
{
  char c;
  int n = 0;
  while (c = getchar())
    if (c != '\n' && c != ' ')
      n = n * 10 + c - '0';
    else
      break;
  return n;
}
void solve()
{
  int n, m, state;
  int row[50] = {}, col[50] = {};
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
    {
      state = Input();
      //scanf("%d", &state);
      row[i] |= state;
      col[j] |= state;
    }

  int row_count = 0, col_count = 0;
  for (int i = 0; i < n; ++i)
  {
    if (!row[i])
      ++row_count;
  }
  for (int i = 0; i < m; ++i)
  {
    if (!col[i])
      ++col_count;
  }
  puts((min(row_count, col_count) & 1) ? "Ashish" : "Vivek");
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
