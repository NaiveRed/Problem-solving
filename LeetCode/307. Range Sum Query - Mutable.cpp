#include <bits/stdc++.h>
using namespace std;

// Fenwick tree (Binary indexed tree)
class NumArray {
 public:
  int bit_size;
  vector<int> BIT;   // Use 1-based index
  vector<int> nums;  // Use 0-based index
  NumArray(vector<int>& nums)
      : bit_size(nums.size() + 1),
        BIT(vector<int>(bit_size)),
        nums(move(nums)) {
    // Build BIT
    for (int i = 1; i < bit_size; ++i) {
      BIT[i] = this->nums[i - 1];
      int left = i - lowbit(i);
      for (int pos = i - 1; pos > left; pos -= lowbit(pos)) BIT[i] += BIT[pos];
    }
  }
  inline int lowbit(int n) { return n & -n; }

  void update(int index, int val) {
    cout << "update" << endl;
    int diff = val - nums[index];
    nums[index] = val;
    ++index;  // 1-based
    while (index < bit_size) {
      BIT[index] += diff;
      index += lowbit(index);
    }
  }

  int query(int index) {
    ++index;  // 1-based
    int sum = 0;
    while (index > 0) {
      sum += BIT[index];
      index -= lowbit(index);
    }
    return sum;
  }
  int sumRange(int left, int right) { return query(right) - query(left - 1); }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
