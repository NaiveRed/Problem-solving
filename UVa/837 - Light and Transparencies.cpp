/*
Problem: ...the X coordinates of the end points are all different from each othe
So don't need to deal with cases like:
x1, x2 (only the x)
1, 2
2, 3
or
1, 2
1, 3
It will be more easy if use another sorted all_x to 
keep all coordinates to find the segments.
*/
#include <cstdio>
#include <algorithm>

struct Point
{
  double x, r;
};
int main()
{
  int T, n;
  double r, x1, x2;
  Point left_x[100], right_x[100];
  char ans[200][30];

  scanf("%d", &T);
  while (T--)
  {
    scanf("%d", &n);
    if (n != 0)
    {
      int idx = 0;
      for (int i = 0; i < n; ++i)
      {
        scanf("%lf%*f%lf%*f%lf", &x1, &x2, &r);
        left_x[i].x = std::min(x1, x2);
        right_x[i].x = std::max(x1, x2);
        left_x[i].r = right_x[i].r = r;
      }
      std::sort(left_x, left_x + n, [](const Point &a, const Point &b) -> bool {
        return a.x < b.x;
      });
      std::sort(right_x, right_x + n, [](const Point &a, const Point &b) -> bool {
        return a.x < b.x;
      });

      int left_idx = 0, right_idx = 0; // Index for sorted left/right point
      int n_seg = 0, zero_percentage = 0;
      double percentage = 1.0, left, right;

      while (left_idx < n || right_idx < n - 1)
      {
        // Find the left point of projected segment
        if (left_idx < n && left_x[left_idx].x < right_x[right_idx].x)
        {
          left = left_x[left_idx].x;
          // The projected segment has already surpassed the left point of
          // the line segment of left_x[left_idx] (the light may propagate)
          if (left_x[left_idx].r <= 1e-8)
            ++zero_percentage;
          else
            percentage *= left_x[left_idx].r;
          ++left_idx;
        }
        else
        {
          left = right_x[right_idx].x;
          // The projected segment has already surpassed the right point of
          // the line segment of right_x[right_idx] (the light will not propagate)
          if (right_x[right_idx].r <= 1e-8)
            --zero_percentage;
          else
            percentage /= right_x[right_idx].r;
          ++right_idx;
        }

        // Find the right point of projected segment
        if (left_idx < n && left_x[left_idx].x < right_x[right_idx].x)
          right = left_x[left_idx].x;
        else
          right = right_x[right_idx].x;

        sprintf(ans[n_seg++], "%.3lf %.3lf %.3lf", left, right, zero_percentage ? 0.0 : percentage);
      }

      printf("%d\n", n_seg + 2);
      printf("-inf %.3lf 1.000\n", left_x[0].x);
      for (int i = 0; i < n_seg; ++i)
        puts(ans[i]);
      printf("%.3lf +inf 1.000\n", right_x[n - 1].x);
    }
    else
      puts("1\n-inf +inf 1.000");

    if (T)
      puts("");
  }

  return 0;
}