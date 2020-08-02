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

int grid[305][305], n, m;
void solve()
{
  bool ans = true;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j)
    {
      scanf("%d", &grid[i][j]);
      if (grid[i][j] > 4)
        ans = false;
    }

  if (grid[1][1] > 2 || grid[1][m] > 2 || grid[n][1] > 2 || grid[n][m] > 2)
    ans = false;
  for (int r = 1; r <= n && ans; ++r)
    if (grid[r][1] > 3 || grid[r][m] > 3)
      ans = false;
  for (int c = 1; c <= m && ans; ++c)
    if (grid[1][c] > 3 || grid[n][c] > 3)
      ans = false;

  if (ans)
  {
    for (int r = 1; r <= n; ++r)
      for (int c = 1; c <= m; ++c)
        grid[r][c] = 4;
    for (int r = 1; r <= n; ++r)
      grid[r][1] = grid[r][m] = 3;
    for (int c = 1; c <= m; ++c)
      grid[1][c] = grid[n][c] = 3;
    grid[1][1] = grid[1][m] = grid[n][1] = grid[n][m] = 2;
    puts("YES");
    for (int i = 1; i <= n; ++i)
      for (int j = 1; j <= m; ++j)
        printf("%d%c", grid[i][j], j != m ? ' ' : '\n');
  }
  else
    puts("NO");
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
