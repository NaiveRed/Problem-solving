#include<cstdio>

int nine_degree(char *str);
int main()
{
	char str[1001];

	while (gets(str)&&str[0]!='0')
	{
		int degree = nine_degree(str);

		if (degree)
			printf("%s is a multiple of 9 and has 9-degree %d.\n", str, degree);
		else
			printf("%s is not a multiple of 9.\n",str);
	}

	return 0;
}
int nine_degree(char *str)
{	
	int num(0), degree(1);

	for (int i = 0; str[i]; i++)
		num += str[i] - '0';

	if (num == 9)
		return 1;

	int sum;

	while(num >= 9)
	{
		sum = 0;
		
		while (num)
		{
			sum += num % 10;
			num /= 10;
		}

		num = sum;

		degree++;

		if (num == 9)
			return degree;
	}

	return 0;
}