#include <climits>
#include <cstdint>
#include <iostream>
using namespace std;

class Solution {
 public:
  // Use only 32-bit integers
  int reverse(int x) {
    int32_t rev = 0;
    while (x) {
      int n = x % 10;
      if ((x > 0 && rev > (INT_MAX - n) / 10) ||
          (x < 0 && rev < (INT_MIN - n) / 10))
        return 0;
      rev = rev * 10 + n;
      x /= 10;
    }
    return rev;
  }
};
int main() {
  Solution solution;
  cout << solution.reverse(-1234) << endl;
}
