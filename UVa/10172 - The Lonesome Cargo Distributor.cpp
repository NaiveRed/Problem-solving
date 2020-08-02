#include <cstdio>
#include <stack>
#include <queue>

std::queue<int> stations[100];
inline bool check(int n)
{
  for (int i = 0; i < n; ++i)
    if (!stations[i].empty())
      return false;

  return true;
}
int main()
{
  int Case = 0;
  scanf("%d", &Case);

  std::stack<int> carrier;
  while (Case--)
  {
    int N, S, Q, cargo, d, time = 0;
    scanf("%d%d%d", &N, &S, &Q);
    for (int i = 0; i < N; ++i)
    {      
      scanf("%d", &cargo);
      for (int j = 0; j < cargo; ++j)
      {        
        scanf("%d", &d);
        stations[i].push(d - 1);
      }
    }

    int pos = 0;
    while (true)
    {
      // Unload to platform A or B
      while (!carrier.empty())
      {
        d = carrier.top();
        if (d != pos)
        {
          if (stations[pos].size() < Q)
          {
            carrier.pop();
            stations[pos].push(d);
          }
          else
            break;
        }
        else
          carrier.pop();
        ++time;
      }

      if (carrier.empty() && check(N))
        break;

      // Take from platform B
      while (!stations[pos].empty() && carrier.size() < S)
      {
        carrier.push(stations[pos].front());
        stations[pos].pop();
        ++time;
      }

      time += 2;
      pos = (pos + 1) % N;
    }

    printf("%d\n", time);
  }
  return 0;
}