#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  // Method 1: T: O(n), S: O(n)
  void rotate(vector<int>& nums, int k) {
    if (k == 0) return;
    int size = nums.size();
    vector<int> ans(size);
    int i = (size - k % size) % size;
    for (int k = 0; k < size; i = (i + 1) % size, ++k) ans[k] = nums[i];
    nums = ans;
  }

  // Method 2: T: O(n), S: O(1) with constant space
  void rotate(vector<int>& nums, int k) {
    int size = nums.size();
    if (!k || !(k % size)) return;
    for (int i = 0, start = 0, current = nums[0], count = 0; count < size;
         ++count) {
      int goal = (i + k) % size, tmp = nums[goal];
      nums[goal] = current;
      current = tmp;
      i = goal;
      if (i == start) {
        current = nums[++i];
        start = i;
      }
    }
  }

  // Method 3: T: O(n), S: O(1) without extra space
  void rotate(vector<int>& nums, int k) {
    k %= nums.size();
    reverse(nums.begin(), nums.end());
    reverse(nums.begin(), nums.begin() + k);
    reverse(nums.begin() + k, nums.end());
  }

  inline void reverse(vector<int>::iterator begin, vector<int>::iterator end) {
    while ((begin != end) && (begin != --end)) {
      if (*begin != *end) swap(begin, end);
      ++begin;
    }
  }

  inline void swap(vector<int>::iterator a, vector<int>::iterator b) {
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
  }
};
int main() {
  Solution solution;
  vector<int> nums{1, 2, 3, 4, 5, 6};
  int k = 2;
  solution.rotate(nums, k);
  for (int& n : nums) cout << n << ' ';
  cout << endl;
  return 0;
}