#include <bits/stdc++.h>
using namespace std;

// Method 1: Time: O(nlogn), Space: O(1)
class Solution {
 public:
  int majorityElement(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    return nums[nums.size() / 2];
  }
};

// Method 2: Time: O(n), Space: O(n)
class Solution1 {
 public:
  int majorityElement(vector<int>& nums) {
    unordered_map<int, int> m;
    int half = nums.size() / 2;
    for (int& n : nums) {
      if (++m[n] > half) return n;
    }
    // Will not come to here. No exist.
    return 0;
  }
};

// Method 3: Boyer Moore Majority Algorithm
// Time: O(n), Space: O(1)
class Solution2 {
 public:
  int majorityElement(vector<int>& nums) {
    int candidate = 0, count = 0;
    for (int& n : nums) {
      if (count)
        count += candidate == n ? 1 : -1;
      else {
        count = 1;
        candidate = n;
      }
    }

    return candidate;
  }
};
