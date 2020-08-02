#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  // Method 1: backtracking
  //     vector<vector<int>> subsets(vector<int>& nums) {
  //         vector<vector<int>> ans;
  //         vector<int> used;
  //         backtrack(nums.size() - 1, nums, used, ans);
  //         return ans;
  //     }
  //     void backtrack(int n, vector<int>& nums, vector<int>& used, vector<vector<int>>& ans)
  //     {
  //         if(n < 0)
  //         {
  //             ans.push_back(used);
  //             return;
  //         }

  //         used.push_back(nums[n]);
  //         backtrack(n-1, nums, used, ans);

  //         used.pop_back();
  //         backtrack(n-1, nums, used, ans);
  //     }

  //Method 2: binary sorted
  vector<vector<int>> subsets(vector<int> &nums)
  {
    int n = pow(2, nums.size());
    vector<vector<int>> ans(n);
    for (int i = 0; i < n; ++i)
    {
      vector<int> ss;
      for (int j = 0; j < nums.size(); ++j)
        if (i & (1 << j))
          ss.push_back(nums[j]);
      ans[i] = move(ss);
    }
    return ans;
  }
};