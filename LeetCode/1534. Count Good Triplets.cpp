#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int countGoodTriplets(vector<int> &arr, int a, int b, int c)
  {
    int len = arr.size(), count = 0;
    ;
    for (int i = 0; i < len - 2; ++i)
      for (int j = i + 1; j < len - 1; ++j)
        for (int k = j + 1; k < len; ++k)
          if (abs(arr[i] - arr[j]) <= a && abs(arr[j] - arr[k]) <= b && abs(arr[i] - arr[k]) <= c)
            ++count;
    return count;
  }
};