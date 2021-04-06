// Refer to 39. combination sum
#include <bits/stdc++.h>
using namespace std;

// Method 1: backtrack with for-loop
// Time: backtracking: O(2^n), sort: O(nlogn)
class Solution {
 public:
  void backtrack(vector<vector<int>>& ans, vector<int>& candidates,
                 vector<int>& combination, int idx, int target) {
    if (!target) {
      ans.push_back(combination);
      return;
    } else if (target < 0)
      return;

    // If the number is the same, it will only call at first time at current
    // for-loop. Then advance to different number.
    // E.g., [... 2, 3, 3, 3, 4,...]
    //
    // [..., 2,3] => [..., 2,3,3] => [..., 2,3,3,3] => [..., 2,3,3,3,4]
    //                            => [..., 2,3,3,4]
    //            => [..., 2,3,4]
    // [..., 2,4] => ...
    for (int i = idx, size = candidates.size(); i < size; ++i) {
      combination.push_back(candidates[i]);
      backtrack(ans, candidates, combination, i + 1, target - candidates[i]);
      combination.pop_back();
      while (i + 1 < size && candidates[i] == candidates[i + 1]) ++i;
    }
  }
  vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    vector<vector<int>> ans;
    vector<int> combination;
    sort(candidates.begin(), candidates.end());
    backtrack(ans, candidates, combination, 0, target);
    return ans;
  }
};

// Method 2: backtrack with index
// Time: backtracking: O(2^n), sort: O(nlogn)
class Solution2 {
 public:
  void backtrack(vector<vector<int>>& ans, vector<int>& candidates,
                 vector<int>& combination, int idx, int target) {
    int size = candidates.size();
    if (target == 0) {
      ans.push_back(combination);
      return;
    } else if (target < 0 || idx >= size)
      return;

    // Use candidates[idx]
    combination.push_back(candidates[idx]);
    backtrack(ans, candidates, combination, idx + 1, target - candidates[idx]);

    // Not use candidates[idx]
    combination.pop_back();
    // Skip duplicated numbers to avoid duplicate combinations
    for (; idx + 1 < size; ++idx)
      if (candidates[idx] != candidates[idx + 1]) {
        backtrack(ans, candidates, combination, idx + 1, target);
        return;
      }
  }
  vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    vector<vector<int>> ans;
    vector<int> combination;
    sort(candidates.begin(), candidates.end());
    backtrack(ans, candidates, combination, 0, target);
    return ans;
  }
};
