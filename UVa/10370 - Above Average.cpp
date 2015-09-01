#include <cstdio>

inline int input();
int main()
{
	int Case = input();

	while (Case--)
	{
		int n = input();
		double ave(0), grade[1000]{0};

		for (int i = 0; i < n; i++)
			ave += (grade[i] = input());
		
		ave /= n;

		int count(0);
		for (int i = 0; i < n; i++)
			if (grade[i]>ave)
				count++;

		printf("%.3lf%%\n", (double)count / n*100);
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