#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int leastInterval(vector<char> &tasks, int n)
  {
    int count[26] = {}, n_maximum = 0, maximum = 0;
    for (char &t : tasks)
      ++count[t - 'A'];

    for (int i = 0; i < 26; ++i)
    {
      if (!count[i])
        continue;
      if (count[i] > maximum)
      {
        // number of task i
        maximum = count[i];
        // number of task which has same number of tasks equal to maximum
        n_maximum = 1;
      }
      else if (count[i] == maximum)
        ++n_maximum;
    }

    // The least number of units we need: (maximum - 1) * (n + 1) + n_maximum
    return max((int)tasks.size(), (maximum - 1) * (n + 1) + n_maximum);
  }
};
