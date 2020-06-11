#include <cstdio>
#include <queue>

struct Register
{
  int num, period, next_time;
  bool operator<(const Register &right) const
  {
    if (next_time == right.next_time)
      return num > right.num;
    return next_time > right.next_time;
  }
};
int main()
{
  std::priority_queue<Register> pq;
  char str[50];
  int num, period;
  while (fgets(str, 50, stdin) && str[0] != '#')
  {
    sscanf(str, "%*s%d%d", &num, &period);
    pq.push({num, period, period});
  }
  int k;
  scanf("%d", &k);
  for (int i = 0; i < k; ++i)
  {
    Register reg = pq.top();
    pq.push({reg.num, reg.period, reg.period + reg.next_time});
    printf("%d\n", reg.num);
    pq.pop();
  }

  return 0;
}