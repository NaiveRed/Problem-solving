#include <cstdio>
#define N 10000

int nums[N], count;
void insertion_sort(int n) {
  if (++count == 1) {
    nums[0] = n;
    return;
  }
  int i = count - 1;
  int key = n;
  // Binary search: find the position to place key
  // i.e. before the one larger than key first occur.
  // if the value is the same, place at rightmost of its value (stable sort)
  // e.g. 1 3 3 3 (new 3) ...
  int low = 0, high = i - 1;
  while (low <= high) {
    // Avoid overflow
    int m = low + (high - low) / 2;
    if (key >= nums[m])
      low = m + 1;
    else
      high = m - 1;
  }
  // low is the position
  for (int j = i; j > low; --j) nums[j] = nums[j - 1];
  nums[low] = key;  // Insert
}
int main() {
  int n;
  while (scanf("%d", &n) != EOF) {
    insertion_sort(n);
    int index = count - 1;
    printf("%d\n", index & 1 ? (nums[index / 2] + nums[index / 2 + 1]) / 2
                             : nums[index / 2]);
  }
  return 0;
}
