#include <cstdio>
#include <algorithm>

struct Point
{
  int x, y;
  bool operator<(const Point &right) const
  {
    if (x != right.x)
      return x < right.x;
    return y < right.y;
  }
} points[4];
//ab dot ac
inline int Dot(const Point &a, const Point &b, const Point &c)
{
  return (b.x - a.x) * (c.x - a.x) + (b.y - a.y) * (c.y - a.y);
}
//ab x ac
inline int Cross(const Point &a, const Point &b, const Point &c)
{
  return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}
inline int Distance_p2(const Point &a, const Point &b)
{
  return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}
inline int Input()
{
  char c;
  int neg = 1, n = 0;
  if ((c = getchar()) == '-')
    neg = -1;
  else
    n += c - '0';
  while (c = getchar())
    if (c != '\n' && c != ' ')
      n = n * 10 + c - '0';
    else
      break;
  return n * neg;
}
int main()
{
  int T;
  scanf("%d ", &T);

  for (int t = 1; t <= T; ++t)
  {
    for (int i = 0; i < 4; ++i)
    {
      points[i].x = Input();
      points[i].y = Input();
      //scanf("%d%d", &points[i].x, &points[i].y);
    }
    std::sort(points, points + 4);
    int hull[5], m = 0;

    // Andrew's Monotone Chain
    // Lower hull
    for (int i = 0; i < 4; ++i)
    {
      while (m >= 2 && Cross(points[hull[m - 2]], points[hull[m - 1]], points[i]) <= 0)
        --m;
      hull[m++] = i;
    }
    // Upper hull
    for (int i = 2, k = m + 1; i >= 0; --i)
    {
      while (m >= k && Cross(points[hull[m - 2]], points[hull[m - 1]], points[i]) <= 0)
        --m;
      if (i == 0)
        break;
      hull[m++] = i; //Will duplicate the first point
    }

    int a = hull[0], b = hull[1], c = hull[2], d = hull[3];
    int dist_a = Distance_p2(points[a], points[b]);

    printf("Case %d: ", t);
    if (m != 4)
      puts("Ordinary Quadrilateral");
    else if (!Dot(points[a], points[b], points[d]) &&
             !Dot(points[b], points[a], points[c]) &&
             !Dot(points[d], points[a], points[c]))
    {
      if (dist_a == Distance_p2(points[a], points[d]))
        puts("Square");
      else
        puts("Rectangle");
    }
    else if (dist_a == Distance_p2(points[a], points[d]) &&
             dist_a == Distance_p2(points[b], points[c]) &&
             dist_a == Distance_p2(points[c], points[d])) // Four sides are equal length
      puts("Rhombus");
    else
    {
      Point origin{};
      int cp_hor = Cross(origin,
                         Point{points[b].x - points[a].x, points[b].y - points[a].y},
                         Point{points[c].x - points[d].x, points[c].y - points[d].y});
      int cp_ver = Cross(origin,
                         Point{points[d].x - points[a].x, points[d].y - points[a].y},
                         Point{points[c].x - points[b].x, points[c].y - points[b].y});
      if (!cp_hor && !cp_ver) // Two pairs of opposite sides are parallel
        puts("Parallelogram");
      else if (!cp_hor || !cp_ver)
        puts("Trapezium");
      else
        puts("Ordinary Quadrilateral");
    }
  }
  return 0;
}