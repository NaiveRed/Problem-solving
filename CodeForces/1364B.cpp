#include <cstdio>
#include <vector>
//#define DEBUG
using namespace std;

int main()
{
#ifdef DEBUG
  freopen("problem.in", "r", stdin);
  freopen("problem.out", "w", stdout);
#endif

  int n, t, p[100000];
  scanf("%d", &t);
  while (t--)
  {
    scanf("%d", &n);
    vector<int> ans;

    for (int i = 0; i < n; ++i)
      scanf("%d", &p[i]);

    ans.push_back(p[0]);
    for (int i = 1; i < n - 1; ++i)
    {
      if ((p[i - 1] > p[i] && p[i] < p[i + 1]) || (p[i - 1] < p[i] && p[i] > p[i + 1]))
        ans.push_back(p[i]);
    }
    ans.push_back(p[n - 1]);

    int len = ans.size();
    printf("%d\n", len);
    for (int i = 0; i < len; ++i)
      printf("%d%c", ans[i], i == len - 1 ? '\n' : ' ');
  }

  return 0;
}