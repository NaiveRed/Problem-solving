#include<cstdio>
#define N 10000

int digit[N][10];

void count();
int input();
int main()
{

	count();

	int Case(input());

	while (Case--)
	{
		int num(input());

		for (int i = 0; i < 10; i++)
			printf("%d%c", digit[num][i], i == 9 ? '\n' : ' ');

	}

	return 0;
}
void count()
{
	digit[1][1] = 1;
	for (int i = 2; i < N; i++)
	{
	
		for (int j = 0; j < 10; j++)
			digit[i][j] = digit[i - 1][j];
		
		int temp(i);
		while (temp)
		{
			digit[i][temp % 10]++;
			temp /= 10;
		}
	}

}
int input()
{
	int num(0);
	char temp;
	while ((temp = getchar()) != '\n')
		num = num * 10 + temp-'0';

	return num;
}