#include<cstdio>

int input();
int main()
{
	int date[13][32];//�@�~12�Ӥ�A�@�Ӥ�̦h31��
	int day[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int Day(6);//2011�~12��31��O�P����

	for (int i = 12; i; i--)
		for (int j = day[i]; j; j--,Day--)
		{
		if (!Day)
			Day = 7;
		date[i][j] = Day;
		}

	char *str[]{"", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};

	int Case=input();

	while (Case--)
	{
		int M = input(), D = input();
		puts(str[date[M][D]]);
	}
	
	return 0;
}
int input()
{
	int num(0);
	char c;

	while ((c = getchar()) != ' '&&c!='\n')
			num = num * 10 + c - '0';
	
	return num;
}