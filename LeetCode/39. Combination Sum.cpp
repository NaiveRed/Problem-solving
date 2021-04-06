// 1. The given array is distinct.
#include <bits/stdc++.h>
using namespace std;

// Method 1: backtracking with for-loop
// Use recursive to form the result (like DFS),
// but use for-loop to iterative all number.
// Time: O(N^target) where N is the length of candidates.
//   Every time we have N choice (repeatedly),
//   and can choose at most `target` times
// Space: O(target)
//
// NOT FOR THIS PROBLEM, but we can show the difference
// between method 1 and 2.
// E.g., [1, 2, 3, 4] (consider to use only one times and recursive to the end)
// => : recursive call
// .[...]: by for-loop
//  [1] => [1,2] => [1,2,3] => [1,2,3,4]
//                 .[1,2,4]
//       .[1,3]  => [1,3,4]
//       .[1,4]
// .[2] => [2,3] => [2,3,4]
//       .[2,4]
// .[3] => [3,4]
// .[4]
class Solution {
 public:
  void backtrack(vector<vector<int>>& ans, vector<int>& candidates,
                 vector<int>& combination, int idx, int target) {
    if (!target) {
      ans.push_back(combination);
      return;
    } else if (target < 0)
      return;

    for (int i = idx, size = candidates.size(); i < size; ++i) {
      // Use candidates[i]
      combination.push_back(candidates[i]);
      // We can use the same combination, so `i` remain the same.
      backtrack(ans, candidates, combination, i, target - candidates[i]);
      // Not use candidates[i]
      combination.pop_back();
    }
  }
  vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> ans;
    vector<int> combination;
    backtrack(ans, candidates, combination, 0, target);
    return ans;
  }
};

// Method 2: backtracking 2
// Use recursive to iterative all numbers (use or not use)
//
// NOT FOR THIS PROBLEM, but we can show the difference
// between method 1 and 2.
// E.g., [1, 2, 3, 4] (consider to use only one times and recursive to the end)
// 0   => 1     => 2       => 3  (idx)
// [1] => [1,2] => [1,2,3] => [1,2,3,4]
//                         => [1,2,3]
//                            if can at here [1,2,3], it will not be the answer.
//                            Otherwise, it will early return at
//                            the previous [1,2,3].
//              => [1,2]   => [1,2,4]
//     => [1]   => [1,3]   => [1,3,4]
//              => [1]     => [1,4]
// [ ] => [2]   => [2,3]   => [2,3,4]
//              => [2]     => [2,4]
//             ...
//     => [ ]

class Solution2 {
 public:
  void backtrack(vector<vector<int>>& ans, vector<int>& candidates,
                 vector<int>& combination, int idx, int target) {
    cout << "target: " << target << " idx: " << idx << endl;
    for (int n : combination) cout << n << " ";
    cout << endl;
    if (!target) {
      ans.push_back(combination);
      return;
    } else if (target < 0 || idx >= candidates.size())
      return;

    // Use candidates[idx]
    combination.push_back(candidates[idx]);
    backtrack(ans, candidates, combination, idx, target - candidates[idx]);

    // Not use candidates[idx]
    combination.pop_back();
    backtrack(ans, candidates, combination, idx + 1, target);
  }
  vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> ans;
    vector<int> combination;
    backtrack(ans, candidates, combination, 0, target);
    return ans;
  }
};
