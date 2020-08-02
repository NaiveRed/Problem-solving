#include <cstdio>
#include <cstring>
int main()
{
  int Case;
  scanf("%d", &Case);
  char str[105];
  while (Case--)
  {
    scanf("%s", str);
    for (int i = 0; str[i]; i += 2)
      putchar(str[i]);
    putchar(str[strlen(str) - 1]);
    putchar('\n');
  }

  return 0;
}