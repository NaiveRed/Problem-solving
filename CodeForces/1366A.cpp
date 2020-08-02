#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
  int t;
  scanf("%d", &t);
  while (t--)
  {
    int a, b;
    scanf("%d%d", &a, &b);
    printf("%d\n", min({a, b, (a + b) / 3}));
  }

  return 0;
}
