#include <cstdio>
#include <cmath>

int main()
{
  int T;
  const double pi = acos(-1.0);
  double L, w, r, red;
  scanf("%d", &T);
  while (T--)
  {
    scanf("%lf", &L);
    w = L * 0.6;
    r = L * 0.2;
    red = r * r * pi;
    printf("%.2lf %.2lf\n", red, w * L - red);
  }

  return 0;
}