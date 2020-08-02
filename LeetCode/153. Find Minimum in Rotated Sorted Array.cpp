#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int findMin(vector<int> &nums)
  {
    int left = 0, right = nums.size() - 1;
    while (left < right)
    {
      int mid = (left + right) >> 1;
      // The rotated point(minimum) is on the left of `mid` or the `mid`
      if (nums[mid] < nums[right])
        right = mid;
      // The rotated point(minimum) is on the right of `mid`
      else // nums[mid] > nums[right]
        left = mid + 1;
    }
    return nums[left];
  }
};