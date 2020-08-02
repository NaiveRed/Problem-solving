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
      // The pivot(minimum) is on the right of `mid`
      if (nums[mid] > nums[right])
        left = mid + 1;
      // The pivot(minimum) is on the left of `mid` or the `mid`
      else if (nums[mid] < nums[right])
      {
        right = mid;
        if (nums[mid] < nums[left])
          ++left;
      }
      // nums[mid] == nums[right], we can not sure where the pivot.
      // (e.g. [3,3,1,3], [1,3,3,3])
      else
        --right;
    }
    return nums[left];
  }
};