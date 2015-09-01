#include <cstdio>

inline int input();
int main()
{
	int set(1);
	int Case, height[50]{0};

	while (Case = input())
	{
		int ave(0),move(0);
		for (int i = 0; i < Case; i++)
			ave += (height[i] = input());

		ave /= Case;
		for (int i = 0; i < Case; i++)
			if (height[i]>ave)
				move += (height[i] - ave);

		for (int i = 0; i < Case; i++)
			height[i] = 0;

		printf("Set #%d\n", set++);
		printf("The minimum number of moves is %d.\n\n", move);

	}

		return 0;
}
int input()
{
	int num(0);
	char c;
	while ((c = getchar()) != ' '&&c != '\n')
		num = num * 10 + c - '0';
	
	return num;
}