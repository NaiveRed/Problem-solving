#include <bits/stdc++.h>
using namespace std;

class Solution {
 private:
  random_device rd;
  default_random_engine gen;
  vector<int> raw;

 public:
  Solution(vector<int>& nums) : gen(rd()), raw(move(nums)) {}

  /** Resets the array to its original configuration and return it. */
  vector<int> reset() { return raw; }

  /** Returns a random shuffling of the array. */
  vector<int> shuffle() {
    vector<int> result(raw);
    // Method 1: use built-in shuffle
    // std::shuffle(result.begin(), result.end(), gen);
    // Method 2: Fisher–Yates shuffle
    for (int i = 0, s = raw.size(); i < s - 1; ++i) {
      int idx = uniform_int_distribution<int>(i, s - 1)(gen);
      swap(result[i], result[idx]);
    }
    return result;
  }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
int main() {
  vector<int> nums{1, 2, 3, 4, 5, 6, 7, 8, 9};
  Solution* obj = new Solution(nums);
  vector<int> param_1 = obj->reset();
  vector<int> param_2 = obj->shuffle();
  for (int n : param_1) cout << n << " ";
  cout << endl;
  for (int n : param_2) cout << n << " ";
  cout << endl;
  return 0;
}
