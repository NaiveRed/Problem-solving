#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  double angleClock(int hour, int minutes)
  {
    // 1 min: 6 degrees
    // 1 hour: 5 minutes => 30 digrees
    // hour hand will increase `5 * (minutes / 60)` min
    // so it will also multiply by 6 degrees
    double hr_hand = 6.0 * 5 * (hour % 12) + 6.0 * 5.0 * minutes / 60;
    double angle = abs(hr_hand - 6.0 * minutes);
    return min(angle, 360 - angle);
  }
};