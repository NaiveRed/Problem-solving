#include <cstdio>

int main()
{
  int m, n;
  float down, loan;
  while (scanf("%d%f%f%d", &m, &down, &loan, &n) && m > 0)
  {
    float car_value = loan + down,
          pay = loan / m, next_depreciation, depreciation;
    int current_month = 0, month = 0;
    bool done = false;
    scanf("%*d%f", &depreciation);
    car_value *= (1.0 - depreciation);
    if (car_value > loan)
      done = true;
    else
      current_month = 1;
    for (int i = 1; i < n; ++i)
    {
      scanf("%d%f", &month, &next_depreciation);
      while (!done)
      {
        if (current_month == month)
        {
          depreciation = next_depreciation;
          break;
        }
        car_value *= (1.0 - depreciation);
        loan -= pay;
        if (car_value > loan)
        {
          done = true;
          break;
        }
        ++current_month;
      }
    }

    while (!done)
    {
      car_value *= (1.0 - depreciation);
      loan -= pay;
      if (car_value > loan)
        break;

      ++current_month;
    }

    printf("%d month%s", current_month, current_month == 1 ? "\n" : "s\n");
  }

  return 0;
}