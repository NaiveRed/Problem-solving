#include <bits/stdc++.h>
using namespace std;

// Method: DP
// Time: O(N^2)
// `length[i]`: length of LIS which ends with nums[i].
// `count[i]`: number of LIS which ends with nums[i] with `length[i]`.
//
// 1. nums[i] > nums[k]: k < i
//     1. length[k] + 1 > length[i],
//         append nums[i] after nums[k] will get larger length.
//         And the number of **these** LIS which ends with nums[i]
//         will be the number of LIS which wnds with nums[k], i.e., `count[k]`
//     2. length[k] + 1 == length[i],
//         append nums[i] after nums[k] will get the same length.
//         Thus update the number of LIS which ends with nums[i]
//         by adding `length[k]`.
// 2. nums[i] <= nums[k]: do nothing
// We can sum the number of all LIS which has the same length as max LIS
class Solution {
 public:
  int findNumberOfLIS(vector<int>& nums) {
    int s = nums.size();
    int length[s], count[s], max_lis = 0;
    for (int i = 0; i < s; ++i) {
      length[i] = count[i] = 1;
      for (int k = 0; k < i; ++k)
        if (nums[i] > nums[k]) {
          // Case 1-1
          if (length[k] + 1 > length[i]) {
            length[i] = length[k] + 1;
            count[i] = count[k];
          } else if (length[k] + 1 == length[i])
            // Case 1-2
            count[i] += count[k];
        }
      max_lis = max(max_lis, length[i]);
    }
    int ans = 0;
    for (int i = 0; i < s; ++i)
      if (length[i] == max_lis) ans += count[i];
    return ans;
  }
};
