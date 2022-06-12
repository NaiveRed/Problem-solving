#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool isSpecial(const char& c) {
        const char s[] = "!@#$%^&*()-+";
        for (const auto& sc : s)
            if (c == sc)
                return true;
        return false;
    }
    bool strongPasswordCheckerII(string password) {
        int n = password.size();
        if (n < 8)
            return false;
        bool isLow = false, isUp = false, isDigit = false, isSpec = false;
        char prev = '\0';
        for (int i = 0; i < n; ++i) {
            if (password[i] == prev) {
                return false;
            }
            if (!isLow && islower(password[i]))
                isLow = true;
            if (!isUp && isupper(password[i]))
                isUp = true;
            if (!isDigit && isdigit(password[i]))
                isDigit = true;
            if (!isSpec && isSpecial(password[i]))
                isSpec = true;
            prev = password[i];
        }
        return isLow && isUp && isDigit && isSpec;
    }
};

