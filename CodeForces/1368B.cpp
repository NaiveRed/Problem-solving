#include <cstdio>
//#include <ctime>
#include <algorithm>
#define dbg(x) cerr << #x " = " << x << endl;
//#define MULTICASE 1
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
  }
#else
  {
    char s[11] = "codeforces";
    long long n, arr[10] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, now = 1;
    scanf("%lld", &n);
    while (now < n)
      for (int i = 0; i < 10 && now < n; ++i)
      {
        now = (now / arr[i]) * (arr[i] + 1);
        ++arr[i];
      }

    for (int i = 0; i < 10; ++i)
      for (int j = 0; j < arr[i]; ++j)
        putchar(s[i]);
  }
#endif

  //fprintf(stderr, "\nRuntime: %.10fs\n", (double)(clock() - tStart) / CLOCKS_PER_SEC);
  return 0;
}
