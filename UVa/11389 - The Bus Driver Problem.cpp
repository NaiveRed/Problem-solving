#include <cstdio>
#include <algorithm>
#include <functional>
using namespace std;

int main()
{
  int n, d, r;
  int morning[10005], evening[10005];
  while (scanf("%d%d%d", &n, &d, &r) && (n || d || r))
  {
    for (int i = 0; i < n; ++i)
      scanf("%d", &morning[i]);

    for (int i = 0; i < n; ++i)
      scanf("%d", &evening[i]);

    sort(morning, morning + n, greater<int>());
    sort(evening, evening + n);
    int count = 0;
    for (int i = 0; i < n; ++i)
      if (morning[i] + evening[i] > d)
        count += morning[i] + evening[i] - d;

    printf("%d\n", count * r);
  }

  return 0;
}