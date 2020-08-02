#include <bits/stdc++.h>
#define DEBUG
using namespace std;

class Solution
{
public:
  string addBinary(string a, string b)
  {
    int carry = 0, a_i = a.size() - 1, b_i = b.size() - 1, s_i = 0;
    string res(max(a_i, b_i) + 1, ' ');
    while (a_i >= 0 && b_i >= 0)
    {
      int an = a[a_i--] - '0', bn = b[b_i--] - '0', n = (an + bn + carry);
      res[s_i++] = ('0' + (n & 1));
      carry = n / 2;           
    }

    while (a_i >= 0)
    {
      int n = a[a_i--] - '0' + carry;
      res[s_i++] = ('0' + (n & 1));
      carry = n / 2;            
    }
    while (b_i >= 0)
    {
      int n = b[b_i--] - '0' + carry;
      res[s_i++] = ('0' + (n & 1));
      carry = n / 2;          
    }
      
    if (carry)
      res.append("1");
    reverse(res.begin(), res.end());
    return res;
  }
};