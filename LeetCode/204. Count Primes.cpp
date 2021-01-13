#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  // Method 1: Sieve of Eratosthenes, O(n loglog n) from wikipedia
  int countPrimes(int n) {
    if (--n < 2) return 0;
    vector<bool> not_prime(n + 1, false);
    not_prime[0] = not_prime[1] = true;
    int _sqrt = sqrt(n), count = 0;
    // build not_prime
    for (int i = 2; i <= _sqrt; ++i) {
      if (!not_prime[i]) {
        // k 從 i 開始
        // 小於 i 的質數在前面做過了;合數則可拆成更前面的質數，所以也已做過
        for (int k = i; i * k <= n; ++k) not_prime[i * k] = true;
      }
    }

    for (bool b : not_prime)
      if (!b) ++count;
    return count;
  }

  // Method 2: Euler Sieve, O(n)
  int countPrimes1(int n) {
    if (--n < 2) return 0;
    int count = 0;
    vector<bool> not_prime(n + 1, false);
    vector<int> prime;
    for (int i = 2; i <= n; ++i) {
      if (!not_prime[i]) prime.push_back(i);
      // 每個合數都只會被刪到一次，用其最小的質因數(prime[p_i])去刪
      for (int p_i = 0; prime[p_i] * i <= n; ++p_i) {
        // 要先篩(放 if 前)，放後面則無法判斷到該合數的質因數次數大於1的
        // 例如 8 應在 4(i) * 2(prime) 時被篩去
        // 12 應在 6(i) * 2(prime) 時被篩去，而不是 4(i) * 3(prime) 時
        not_prime[prime[p_i] * i] = true;
        // Case 1: i 是質數，i % prime[p_i] = i % i 時停下
        // (i 為目前表中最後一個質數) 同時也符合我們想要用其最小的質因數去刪。
        // Case 2: i 是合數且其質因數包含 prime[p_i]，此時 prime[p_i] * i
        // 可被拆成更小的 prime[p_i] 在較大的 i 時被篩 (如上 12 的例子)
        if (i % prime[p_i] == 0) break;
      }
    }
    return prime.size();
  }
};

int main() {
  Solution sol;
  sol.countPrimes(10);
  return 0;
}
