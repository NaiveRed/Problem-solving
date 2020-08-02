#include <cstdio>
//#include <ctime>
#include <algorithm>
#define dbg(x) cerr << #x " = " << x << endl;
#define MULTICASE 1
#define CASET         \
  int ___T;           \
  scanf("%d", &___T); \
  for (int _t = 1; _t <= ___T; ++_t)
using namespace std;

int main()
{
  //freopen("problem.in", "r", stdin);
  // freopen("problem.out", "w", stdout);
  // ios_base::sync_with_stdio(false);
  // cin.tie(0);
  //clock_t tStart = clock();

#if MULTICASE
  CASET
  {
    int a, b, n, mi, ma, ans = 0;
    scanf("%d%d%d", &a, &b, &n);
    mi = min(a, b);
    ma = max(a, b);
    if (ma <= n)
    {
      while (mi + ma <= n)
      {
        mi += ma;
        int tmp = mi;
        mi = ma;
        ma = tmp;
        ++ans;
      }
      printf("%d\n", ans + 1);
    }
    else
      puts("0");
  }
#else
  {
    /*...*/
  }
#endif

  //fprintf(stderr, "\nRuntime: %.10fs\n", (double)(clock() - tStart) / CLOCKS_PER_SEC);
  return 0;
}
