#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    double calculateTax(vector<vector<int>>& brackets, int income) {

        double tax = 0;
        int prev_upper = 0;
        for (const auto& bracket : brackets) {
            int diff = bracket[0] - prev_upper;
            tax += (double)bracket[1] * min(diff, income);
            income -= diff;
            if (income <= 0)
                break;
            prev_upper = bracket[0];
        }
        return tax / 100;
    }
};

