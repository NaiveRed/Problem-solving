#include <bits/stdc++.h>
using namespace std;

// Method 1: DP, use `len[i]` to keep LIS which ends with nums[i].
// Time: O(n^2)
class Solution {
 public:
  int lengthOfLIS(vector<int>& nums) {
    int size = nums.size();
    int len[size], lis = 0;
    for (int i = 0; i < size; ++i) {
      len[i] = 1;
      for (int k = 0; k < i; ++k)
        if (nums[i] > nums[k]) len[i] = max(len[i], len[k] + 1);
      lis = max(lis, len[i]);
    }
    return lis;
  }
};

// Method 2: Robinson-Schensted-Knuth Algorithm
// Time: O(n log n)
class Solution1 {
 public:
  int lengthOfLIS(vector<int>& nums) {
    int size = nums.size();
    if (!size) return 0;
    vector<int> lis;
    lis.push_back(nums[0]);
    for (int i = 1; i < size; ++i) {
      if (nums[i] > lis.back())
        lis.push_back(nums[i]);
      else
        // nums[i]<=lis.back(), if use upper_bound, we need to deal with not
        // found case(i.e. nums[i]==lis.back())
        *lower_bound(lis.begin(), lis.end(), nums[i]) = nums[i];
    }
    return lis.size();
  }
};

// Method 3: Use `lis[i]` to keep the end number of LIS with length `i`
// Time: O(NL), L is length of LIS
class Solution2 {
 public:
  int lengthOfLIS(vector<int>& nums) {
    int size = nums.size();
    if (!size) return 0;

    int lis[size + 1];
    lis[0] = -1e5;
    for (int i = 1; i <= size; ++i) lis[i] = 1e5;

    int length = 0;
    for (int i = 0; i < size; ++i) {
      if (nums[i] > lis[length]) ++length;

      // For each LIS with different length, check whether n is a better choice.
      for (int k = 1; k <= length; ++k) {
        if (nums[i] > lis[k - 1])  // Place after `k-1`
          lis[k] = min(lis[k], nums[i]);
      }
    }
    return length;
  }
};
