#include <stdio.h>

int removeDuplicates(int* nums, int numsSize) {
  int idx = 0;
  for (int i = 0; i < numsSize; ++i) {
    if (nums[i] != nums[idx]) nums[++idx] = nums[i];
  }
  return numsSize ? (idx + 1) : 0;
}
int main() {
  int nums[] = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4},
      size = sizeof(nums) / sizeof(int);
  int length = removeDuplicates(nums, size);
  printf("%d\n", length);
  for (int i = 0; i < length; ++i) printf("%d ", nums[i]);
  puts("");
  return 0;
}
