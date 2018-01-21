#include <cstdio>
#include <cstring>

int cycle[10] = {66}, cycle_length;
int trial()
{
	const int res = 66 % 100;
	int len = 1, start = 0;
	int appear[100] = {}; //已出現過的位置
	for (int i = 0; i < 100; i++)
		appear[i] = -1;

	while (true)
	{
		//start from 66^2
		cycle[len] = (cycle[len - 1] * res) % 100;
		if (appear[cycle[len]] != -1)
		{
			cycle_length = len - appear[cycle[len]];
			start = appear[cycle[len]];
			len++;
			break;
		}

		appear[cycle[len]] = len;
		len++;
	}

	return start;
}
int main()
{
	//n = 0: 1
	//index:  0  1  2  3  4  5
	//result: 66 56 96 36 76 16 56 ...
	//n:      1  2  3  4  5  6
	//cycle_length = 5
	
	int start = trial();
	//for (int i = 0; i < start + cycle_length; i++)
	//	printf("%d ", cycle[i]);

	int T;
	scanf("%d ", &T);
	char str[1005];
	while (T--)
	{
		fgets(str, 1005, stdin);
		int len = strlen(str);
		str[--len] = '\0';
		int idx = -1;
		if (str[len - 1] == '0')
			idx = 8;
		else if (str[len - 1] == '1')
			idx = 9;
		else
			idx = str[len - 1] - '0' - 2;

		if (len == 1 && str[0] == '0')
			puts("1");
		else if (len == 1 && str[0] == '1')
			puts("66");
		else
			printf("%d\n", cycle[(idx % cycle_length) + 1]);
	}

	return 0;
}