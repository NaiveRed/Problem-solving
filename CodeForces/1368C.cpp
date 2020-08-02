#include <bits/stdc++.h>
#define dbg(x) cerr << #x " = " << x << endl;
//#define MULTICASE 1
#define CASET         \
  int ___T;           \
  scanf("%d", &___T); \
  for (int _t = 1; _t <= ___T; ++_t)
using namespace std;

int main()
{
  // freopen("problem.in", "r", stdin);
  // freopen("problem.out", "w", stdout);
  // ios_base::sync_with_stdio(false);
  // cin.tie(0);
  // clock_t tStart = clock();

#if MULTICASE
  CASET
  {
  }
#else
  {
    int n;
    vector<pair<int, int>> pos;
    scanf("%d", &n);

    pos.push_back({0, 0});
    pos.push_back({0, 1});
    pos.push_back({1, 0});
    pos.push_back({1, 1});
    pos.push_back({1, 2});
    pos.push_back({2, 1});
    pos.push_back({2, 2});
    for (int i = 2; i <= n; ++i)
    {
      pos.push_back({i, i + 1});
      pos.push_back({i + 1, i});
      pos.push_back({i + 1, i + 1});
    }

    printf("%d\n", (int)pos.size());
    for (auto &p : pos)
      printf("%d %d\n", p.first, p.second);
  }
#endif

  //fprintf(stderr, "\nRuntime: %.10fs\n", (double)(clock() - tStart) / CLOCKS_PER_SEC);
  return 0;
}
