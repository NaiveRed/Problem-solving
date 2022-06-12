#include <bits/stdc++.h>
using namespace std;

// Iterative version
class Solution1 {
  public:
    int minMaxGame(vector<int>& nums) {
        size_t len = nums.size();
        while (len != 1) {
            size_t n = len >> 1;
            for (size_t i = 0; i < n; ++i) {
                size_t idx = i << 1;
                nums[i] = (i & 1) ? max(nums[idx], nums[idx + 1])
                                  : min(nums[idx], nums[idx + 1]);
            }
            len = n;
        }
        return nums[0];
    }
};


// Recursive version
class Solution2 {
  public:
    int (*func[2])(int,
                   int) = {[](int a, int b) -> int { return (a < b) ? a : b; },
                           [](int a, int b) -> int { return (a < b) ? b : a; }};
    int minMaxGame(vector<int>& nums) {
        return helper(nums, 0, nums.size(), 0);
    }
    int helper(const vector<int>& nums, size_t left, size_t right,
               size_t flag) {
        if (right - left >= 2) {
            size_t m = (left + right) >> 1;
            return (*func[flag])(helper(nums, left, m, 0),
                                 helper(nums, m, right, 1));
        }
        return nums[left];
    }
};
