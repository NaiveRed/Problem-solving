#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<int> prisonAfterNDays(vector<int> &cells, int N)
  {
    // Find pattern
    int pattern[1 << 6] = {0}, next[8] = {}, step;
    vector<int> record;

    for (step = 1; step <= N; ++step)
    {
      // The first and last cell will be always zero
      for (int j = 1; j < 7; ++j)
        next[j] = cells[j - 1] == cells[j + 1] ? 1 : 0;

      int enc = encode(next), cycle_start = pattern[enc];      
      if (cycle_start)
      {      
        // N - cycle_start + 1: 在 cycle 中剩下的數量        
        int cycle_length = step - cycle_start;
        return decode(record[cycle_start - 1 + ((N - cycle_start) % cycle_length)]);
      }
      else
      {
        pattern[enc] = step;
        record.push_back(enc);
        for (int j = 0; j < 8; ++j)
          cells[j] = next[j];
      }
    }

    return cells;
  }

  inline int encode(int *cells)
  {
    int n = 0;
    for (int i = 1; i < 7; ++i)
      n = (n << 1) + cells[i];
    return n;
  }

  inline vector<int> decode(int n)
  {
    vector<int> res(8);
    for (int i = 6; i > 0; --i)
    {
      res[i] = n & 1;
      n >>= 1;
    }
    return res;
  }
};