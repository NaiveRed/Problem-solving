#include<cstdio>
#include<algorithm>
#define N 2000001

int age[N];

inline int input();
inline void output(int Case);
int main()
{
	int Case;

	while ((Case = input()) != 0)
	{
		for (int i = 0; i < Case; i++)
			age[i] = input();

		std::sort(age, age + Case);

		output(Case);
	}

	return 0;
}
int input()
{
	char c;
	int num(0);
	while ((c = getchar()) != '\n'&&c != ' ')
		num = num * 10 + (c - '0');

	return num;
}
void output(int Case)
{
	if (age[0] >= 10)
	{
		putchar((age[0] / 10) + '0');
		putchar((age[0] % 10) + '0');
	}
	else
		putchar(age[0] + '0');
	
	for (int i = 1; i < Case; i++)
	{
		putchar(' ');
		if (age[i] >= 10)
		{
			putchar((age[i] / 10)+'0');
			putchar((age[i] % 10)+'0');	
		}
		else
			putchar(age[i] + '0');	
	}
	putchar('\n');
}