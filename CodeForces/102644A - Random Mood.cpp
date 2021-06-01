// gym: Matrix Exponentiation
#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  double p, happy_prob = 1.0;
  scanf("%d%lf", &n, &p);
  // Binary Exponentiation
  // With each iteration: p -> p2 -> p4 -> p8
  // the prob to switch the mood after n minutes (p2: 2 minutes)
  while (n) {
    if (n & 1) {
      // happy -> happy (no switch): happy_prob * (1 - p)
      // sad -> happy (switch): (1 - happy_prob) * p
      happy_prob = happy_prob * (1 - p) + (1 - happy_prob) * p;
    }
    // p * (1 - p):
    //  switch -> no switch => switch
    // (1 - p) * p:
    //  no switch -> switch => switch
    p = p * (1 - p) + (1 - p) * p;
    n >>= 1;
  }

  printf("%.9lf\n", happy_prob);

  return 0;
}
