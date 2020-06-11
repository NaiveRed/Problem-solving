#include <cstdio>
#include <cctype>
#include <cstring>
#include <unordered_map>
#include <string>
#include <algorithm>
using namespace std;

struct Recipe
{
  string name;
  int cost;
  bool operator<(const Recipe &right) const
  {
    if (cost == right.cost)
      return name.compare(right.name) < 0;
    return cost < right.cost;
  }
};
int main()
{
  int t, m, n, b, k, price;
  char title[100], str[100];
  Recipe recipes[100];
  unordered_map<string, int> ingredient;
  scanf("%d", &t);
  while (t--)
  {
    getchar();
    fgets(title, 100, stdin);

    scanf("%d%d%d", &m, &n, &b);
    for (int i = 0; i < m; ++i)
    {
      scanf("%s%d", str, &price);
      ingredient.insert({str, price});
    }
    // Recipe
    int idx = 0;
    for (int i = 0; i < n; ++i)
    {
      getchar();
      fgets(str, 100, stdin);
      str[strlen(str) - 1] = '\0';
      recipes[idx].name = string(str);
      recipes[idx].cost = 0;
      scanf("%d", &k);
      int unit;
      for (int j = 0; j < k; ++j)
      {
        scanf("%s%d", str, &unit);
        recipes[idx].cost += ingredient[str] * unit;
      }

      if (recipes[idx].cost <= b)
        ++idx;
    }

    for (int i = 0; title[i]; ++i)
      putchar(toupper(title[i]));

    if (idx)
    {
      sort(recipes, recipes + idx);
      for (int i = 0; i < idx; ++i)
        puts(recipes[i].name.c_str());
    }
    else
      puts("Too expensive!");

    putchar('\n');

    ingredient.clear();
  }

  return 0;
}