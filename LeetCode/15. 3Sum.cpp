#include <bits/stdc++.h>
using namespace std;

class Solution
{

public:
  vector<vector<int>> threeSum(vector<int> &nums)
  {

    int i = 0, len = nums.size();
    if (len < 3)
      return {};
    sort(nums.begin(), nums.end());
    if (nums.front() > 0 || nums.back() < 0)
      return {};

    vector<vector<int>> ans;
    while (i < len - 2)
    {
      int a = nums[i], target = -a;
      // Pruning
      if (a > 0)
        break;
      int start = i + 1, end = len - 1;
      while (start < end)
      {
        if (nums[start] + nums[end] > target)
          --end;
        else if (nums[start] + nums[end] < target)
          ++start;
        else
        {
          int b = nums[start];
          ans.push_back({a, b, nums[end]});
          while (start < end && nums[start] == nums[start + 1])
            ++start;
          while (start < end && nums[end] == nums[end - 1])
            --end;
          ++start;
          --end;
        }
      }
      while (i + 1 < len && nums[i] == nums[i + 1])
        ++i;
      ++i;
    }

    return ans;
  }
};