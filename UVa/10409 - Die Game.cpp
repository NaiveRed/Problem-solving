#include<cstdio>

int main()
{
	int n;

	while (scanf("%d", &n) && n)
	{
		getchar();
		int top(1), bottom(6), north(2), south(5), east(4), west(3),temp;
		char str[6];
		for (int i = 0;i<n;i++)
		{
			gets(str);

			switch (str[0])
			{
			case 'n':
				temp = top;
				top = south;
				south = bottom;
				bottom = north;
				north = temp;
				break;
			case 's':
				temp = top;
				top = north;
				north = bottom;
				bottom = south;
				south = temp;
				break;
			case 'e':
				temp = top;
				top = west;
				west = bottom;
				bottom = east;
				east = temp;
				break;
			case 'w':
				temp = top;
				top = east;
				east = bottom;
				bottom = west;
				west = temp;
				break;
			}
		}

		printf("%d\n", top);
	}

	return 0;
}