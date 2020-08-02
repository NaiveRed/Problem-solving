#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int Case, n, x, m, l, r;
  cin >> Case;
  while (Case--)
  {
    cin >> n >> x >> m;
    int ans_l = x, ans_r = x;
    for (int i = 0; i < m; ++i)
    {
      cin >> l >> r;
      if (r >= ans_l && l <= ans_r)
      {
        ans_l = min(ans_l, l);
        ans_r = max(ans_r, r);
      }
    }
    cout << ans_r - ans_l + 1 << '\n';
  }

  return 0;
}