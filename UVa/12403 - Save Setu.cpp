#include <cstdio>
#include <cstring>
int main()
{
	int T;
	scanf("%d ", &T);
	char str[50];
	int money = 0;
	while (T--)
	{
		fgets(str, 50, stdin);
		str[strlen(str)-1] = NULL;
		if (str[0] == 'd')
		{
			int temp;
			sscanf(str + 7, "%d", &temp);
			money += temp;
		}
		else
			printf("%d\n", money);
	}
	return 0;
}