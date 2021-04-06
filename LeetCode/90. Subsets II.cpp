#include <bits/stdc++.h>
using namespace std;

// Method 1: Iterative
// nums: 1, 2, 2, 3
// subsets: {}
// i=0: [{}, {1}]; start_idx=0
// i=1: [{}, {1}, {2}, {1,2}]; start_idx=0
// i=2: [{}, {1}, {2}, {1,2}]; prev_sub_idx=2, start_idx=prev_sub_idx
//                ---------- We will use only these two subsets
//     => [{}, {1}, {2}, {1,2}, {2,2}, {1,2,2}];
// i=3: [{}, {1}, {2}, {1,2}, {2,2}, {1,2,2}, {3}, {1,3}, {2,3}, {1,2,3},
//      {2,2,3}, {1,2,2,3}]; start_idx=0
class Solution {
 public:
  vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    // For determining dup number
    sort(nums.begin(), nums.end());

    vector<vector<int>> subsets;
    subsets.push_back({});
    // The start-index of subset we added for previous number.
    int prev_sub_idx = 0;
    for (int i = 0, size = nums.size(); i < size; ++i) {
      // The index of subset we start to add nums[i] for new subsets.
      int start_idx = 0, ss = subsets.size();
      // If the number is dup, we need to use subsets we created in previous
      // round to avoid the same sets.
      if (i && nums[i] == nums[i - 1]) start_idx = prev_sub_idx;

      // Use old subsets to build new sets.
      while (start_idx < ss) {
        subsets.push_back(subsets[start_idx++]);
        subsets.back().push_back(nums[i]);
      }
      // Update idx to the start index of new subset of current num[i].
      prev_sub_idx = ss;
    }
    return subsets;
  }
};

// Method 2: Recursive
// nums: [1,2_a,2_b,2_c,3,4]
// (): means the new added
// {}
//     i=0, {(1)}
//         i=1, {1,(2_a)}
//             i=2, {1,2,(2_b)}
//                 i=3, {1,2,2,(2_c)}
//                     i=4, {1,2,2,2,(3)}
//                         ...
//                 i=4, {1,2,2,(3)}
//                     ...
//                 i=5, {1,2,2,(4)}
//             i=3, {1,2,(2_c)}, SKIP
//                 2_c==a_b, we already processed subset of 2 at previous round.
// Two conditions we will add it to our subset:
// 1. it is the first number in this round
// 2. it is different from previous number
//     (no need to compare with number which has already been in subset)
class Solution2 {
 public:
  vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    // For determining dup number
    sort(nums.begin(), nums.end());
    vector<vector<int>> subsets;
    vector<int> current;
    helper(nums, subsets, current, 0);
    return subsets;
  }
  void helper(vector<int>& nums, vector<vector<int>>& subsets,
              vector<int>& current, int idx) {
    subsets.push_back(current);
    if (idx >= nums.size()) return;
    for (int i = idx, s = nums.size(); i < s; ++i) {
      if (i == idx || nums[i] != nums[i - 1]) {
        current.push_back(nums[i]);
        helper(nums, subsets, current, i + 1);
        current.pop_back();
      }
    }
  }
};
