#include <bits/stdc++.h>
using namespace std;

class NumArray {
 public:
  vector<int> prefix_sum;
  NumArray(vector<int>& nums) {
    prefix_sum.push_back(0);
    for (int& n : nums) {
      prefix_sum.push_back(prefix_sum.back() + n);
    }
  }

  int sumRange(int left, int right) {
    return prefix_sum[right + 1] - prefix_sum[left];
  }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
int summation(int x, int y) { return x + y; }
class SparseTable {
 public:
  // table[p][i]: the range of [i, i+(2^p)-1]
  // size = nums.size()
  // p: floor(log2(size))+1
  // i: size
  // E.g., size = 8 => table[4][8]
  //    range(len): 2^0, 2^1, 2^2, 2^3
  //     , size = 7 => table[3][8]
  //    range(len): 2^0, 2^1, 2^2
  int n_size;
  int p_max;
  vector<int> log2_table;  // Precomputed the log2(n)
  vector<vector<int>> table;
  int (*func)(int, int);

  // Precomputation, construct the table
  // Time: O(NlogN)
  // Space: O(NlogN)
  SparseTable(vector<int>& nums, int (*f)(int, int))
      : n_size(nums.size()),
        // That is floor(log2(nums.size())), can use GCC built-in __builtin_clz
        p_max(31 - __builtin_clz(nums.size())),
        log2_table(nums.size() + 1),
        table(p_max + 1, vector<int>(nums.size())),
        func(f) {
    // Precomputed the log2(n)
    log2_table[1] = 0;
    for (int i = 2; i <= n_size; ++i) log2_table[i] = log2_table[i >> 1] + 1;

    // Base case, length = 2^0, p=0
    for (int i = 0; i < n_size; ++i) table[0][i] = nums[i];

    // For each range 2^p
    for (int p = 1; p <= p_max; ++p)
      for (int i = 0; i + (1 << p) <= n_size; ++i) {
        // Compute the range [i, i+(2^p)-1]
        // with left and right adjacent interval without overlap.
        // table[p - 1][i]: left
        // table[p - 1][i + 2^(p-1)]: right
        table[p][i] = f(table[p - 1][i], table[p - 1][(i + (1 << (p - 1)))]);
      }
  }

  // If our query is summation: simillar to BIT
  // Time: O(log n)
  // E.g., [1, 13] = [1,8] + [9,12] + [13,13]
  //      len = 13 => 1101(binary) => len(8)+len(4)+len(1)
  int query_sum(int l, int r) {
    int sum = 0;
    for (int p = log2_table[r - l + 1]; p >= 0; --p) {
      // The remain interval is [l, r]
      // The next query range: [l, l + (1 << p) - 1]
      // So l + (1 << p) - 1 <= r
      if (l + (1 << p) - 1 <= r) {
        sum += table[p][l];
        l += (1 << p);  // Advance the `l` to the next interval
      }
    }
    return sum;
  }
};

class NumArray {
 public:
  SparseTable st;
  NumArray(vector<int>& nums) : st(nums, summation) {}
  int sumRange(int left, int right) { return st.query_sum(left, right); }
};
