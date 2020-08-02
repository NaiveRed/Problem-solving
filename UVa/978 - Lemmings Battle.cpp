#include <cstdio>
//#include <iostream>

inline int Input()
{
  char c;
  int n = 0;
  while (c = getchar())
    if (c != '\n' && c != ' ')
      n = n * 10 + c - '0';
    else
      break;
  return n;
}
int main()
{
  // std::ios_base::sync_with_stdio(false);
  // std::cin.tie(0);

  int Case;
  //std::cin >> Case;
  scanf("%d ", &Case);
  int results[100000] = {};
  while (Case--)
  {
    int p, power_G[128] = {}, power_B[128] = {};
    int B, SG, SB, g_pos = 0, b_pos = 0;
    //std::cin >> B >> SG >> SB;
    B = Input();
    SG = Input();
    SB = Input();
    for (int i = 0; i < SG; ++i)
    {
      //std::cin >> p;
      p = Input();
      ++power_G[p];
      if (p > g_pos)
        g_pos = p;
    }
    for (int i = 0; i < SB; ++i)
    {
      //std::cin >> p;
      p = Input();
      ++power_B[p];
      if (p > b_pos)
        b_pos = p;
    }

    while (g_pos && b_pos)
    {
      int b = 0;
      while (b < B && g_pos && b_pos)
      {
        results[b++] = g_pos - b_pos;
        --power_G[g_pos];
        --power_B[b_pos];
        while (g_pos && !power_G[g_pos])
          --g_pos;
        while (b_pos && !power_B[b_pos])
          --b_pos;
      }

      for (int i = 0; i < b; ++i)
      {
        if (results[i] > 0) // Green wins
        {
          ++power_G[results[i]];
          if (g_pos < results[i])
            g_pos = results[i];
        }
        else if (results[i] < 0) // Blue wins
        {
          results[i] *= -1;
          ++power_B[results[i]];
          if (b_pos < results[i])
            b_pos = results[i];
        }
      }
    }

    if (g_pos)
    {
      //std::cout << "green wins\n";
      puts("green wins");
      while (g_pos)
      {
        while (power_G[g_pos]--)
          //std::cout << g_pos << '\n';
          printf("%d\n", g_pos);
        --g_pos;
      }
    }
    else if (b_pos)
    {
      //std::cout << "blue wins\n";
      puts("blue wins");
      while (b_pos)
      {
        while (power_B[b_pos]--)
          //std::cout << b_pos << '\n';
          printf("%d\n", b_pos);
        --b_pos;
      }
    }
    else
      //std::cout << "green and blue died\n";
      puts("green and blue died");

    if (Case)
      //std::cout << '\n';
      puts("");
  }

  return 0;
}