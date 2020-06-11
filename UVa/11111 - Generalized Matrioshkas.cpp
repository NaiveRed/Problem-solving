// There may be space between two consecutive numbers
#include <cstdio>
#include <cmath>
#include <stack>

char str[30000];
inline int Input(size_t &idx)
{
  char c;
  int neg = 1, n = 0;
  if (str[idx] == '-')
    neg = -1;
  else
    n += str[idx] - '0';
  ++idx;
  while (str[idx] != EOF && str[idx] != '\n' && str[idx] != ' ')
  {
    n = n * 10 + str[idx] - '0';
    ++idx;
  }

  return n * neg;
}
int main()
{
  while (fgets(str, 30000, stdin) != NULL)
  {
    bool ans = true;
    std::stack<int> s;
    int contained[10000] = {};
    size_t idx = 0;
    while (str[idx] != '\n')
    {
      int n = Input(idx);
      while (str[idx] == ' ')
        ++idx;
      if (!s.empty() && n == s.top())
      {
        s.pop();

        // Check the toy inside the top one can be allocated inside it.
        if (contained[s.size()] >= n)
          ans = false;
      }
      else
      {
        n = abs(n);
        s.push(n);
        size_t size = s.size();
        contained[size - 1] = 0;
        if (size > 1)
          contained[size - 2] += n;
      }
    }
    puts((ans && s.empty()) ? ":-) Matrioshka!" : ":-( Try again.");
  }

  return 0;
}
