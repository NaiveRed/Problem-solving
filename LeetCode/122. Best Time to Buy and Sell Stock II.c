#include <stdio.h>

int maxProfit(int* prices, int pricesSize) {
  int ans = 0;
  for (int i = 1; i < pricesSize; ++i) {
    if (prices[i] > prices[i - 1]) {
      ans += prices[i] - prices[i - 1];
    }
  }
  return ans;
}
int main() {
  int nums[] = {7, 1, 5, 3, 6, 4}, size = sizeof(nums) / sizeof(int);
  printf("%d\n", maxProfit(nums, size));
  return 0;
}