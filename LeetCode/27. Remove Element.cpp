#include <bits/stdc++.h>
using namespace std;

// O(n), more assignment when the "val" are more than "non-val"
class Solution {
  public:
    int removeElement(vector<int>& nums, int val) {
        int head = 0, tail = nums.size() - 1;
        while (head <= tail) {
            if (nums[tail] == val)
                --tail;
            else {
                if (nums[head] == val) {
                    nums[head] = nums[tail--];
                }
                ++head;
            }
        }
        return tail + 1;
    }
};

// O(N), more assignment when "non-val" more than "val"
class Solution1 {
  public:
    int removeElement(vector<int>& nums, int val) {
        int idx = 0, tail = nums.size() - 1;
        for (int i = 0, n = nums.size(); i < n; ++i) {
            if (nums[i] != val)
                nums[idx++] = nums[i];
        }
        return idx;
    }
};
