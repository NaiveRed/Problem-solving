#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  // Method 1: backtracking
  // Time: O(n x 2^n)
  // order: [[3,2,1], [3,2], [3,1], [3], [2,1], [2], [1], []]
  vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> ans;
    vector<int> used;
    backtrack(nums.size() - 1, nums, used, ans);
    return ans;
  }
  void backtrack(int n, vector<int>& nums, vector<int>& used,
                 vector<vector<int>>& ans) {
    if (n < 0) {
      ans.push_back(used);
      return;
    }

    used.push_back(nums[n]);
    backtrack(n - 1, nums, used, ans);

    used.pop_back();
    backtrack(n - 1, nums, used, ans);
  }
};

// Method 2: backtracking 2
// Time: O(n x 2^n)
// order: [[], [1], [1,2], [1,2,3], [1,3], [2], [2,3], [3]]
class Solution1 {
 public:
  vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> ans;
    vector<int> used;
    backtrack(0, nums.size() - 1, nums, used, ans);
    return ans;
  }
  // from s to n
  void backtrack(int s, int n, vector<int>& nums, vector<int>& used,
                 vector<vector<int>>& ans) {
    ans.push_back(used);
    if (s > n) return;
    for (; s <= n; ++s) {
      used.push_back(nums[s]);
      backtrack(s + 1, n, nums, used, ans);
      used.pop_back();
    }
  }
};

// Method 3: binary sorted
// Time: O(n x 2^n)
class Solution2 {
 public:
  vector<vector<int>> subsets(vector<int>& nums) {
    int size = nums.size(), n = 1 << size;
    vector<vector<int>> ans(n);
    for (int i = 0; i < n; ++i) {
      for (int b = 0; b < size; ++b)  // bit
        if (i & (1 << b)) ans[i].push_back(nums[b]);
    }
    return ans;
  }
};

// Method 4: iterative
// Time: O(n x 2^n)
class Solution3 {
 public:
  vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> ans;
    ans.push_back({});
    for (int& n : nums) {
      int size = ans.size();
      for (int i = 0; i < size; ++i) {
        ans.push_back(ans[i]);
        ans.back().push_back(n);
      }
    }
    return ans;
  }
};
