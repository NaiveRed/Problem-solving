#include <cstdio>
#define M 500000

inline int dir_to_idx(char sign, char dir)
{
  int idx = -1;
  if (sign == '+')
  {
    if (dir == 'x')
      idx = 4;
    else if (dir == 'y')
      idx = 0;
    else //'z'
      idx = 2;
  }
  else //'-'
  {
    if (dir == 'x')
      idx = 5;
    else if (dir == 'y')
      idx = 1;
    else //'z'
      idx = 3;
  }

  return idx;
}
int main()
{
  int L;
  char command[M];
  const char output[6][3] = {"+y",
                             "-y",
                             "+z",
                             "-z",
                             "+x",
                             "-x"};
  const int map[6][4] = {
      {5, 4, 0, 0}, //+y
      {4, 5, 1, 1}, //-y
      {2, 2, 5, 4}, //+z
      {3, 3, 4, 5}, //-z
      {0, 1, 2, 3}, //+x
      {1, 0, 3, 2}, //-x
  };
  while (scanf("%d ", &L) && L > 0)
  {    
    int ans = 4; //+x
    fgets(command, M, stdin);

    for (int i = 0; i < L - 1; ++i)
    {
      char sign = command[i * 3], dir = command[i * 3 + 1];      
      if (sign == 'N')
        continue;
      int idx = dir_to_idx(sign, dir);
      ans = map[ans][idx];
    }

    puts(output[ans]);
  }

  return 0;
}