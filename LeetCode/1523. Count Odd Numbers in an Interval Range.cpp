#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int countOdds(int low, int high)
  {
    // The count of odd between 1 and low-1
    int l_count = low / 2;
    // The count of odd between 1 and high
    int h_count = (high / 2) + (high & 1); //or (high + 1)/2
    return h_count - l_count;
  }
};
