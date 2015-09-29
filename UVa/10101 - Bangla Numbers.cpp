#include<cstdio>
#define ll long long

inline ll input();
void Bangla(ll num);
int main()
{
	int Case(1);
	ll num;

	while ((num=input())!=EOF)
		{

		printf("%4d.", Case++);

		if (num)
			Bangla(num);
		else
			printf(" 0");
		
		putchar('\n');

		}

	return 0;
}
ll input()
{

	ll num = 0;
	char c;

	while ((c = getchar()) != '\n')
	{
		if (c == EOF)
			return EOF;
		num = num * 10 + c - '0';
	}

	return num;
}
void Bangla(ll num)
{

	if (!num)
		return ;

	if (num / 10000000)
	{
		Bangla(num / 10000000);
		num %= 10000000;
		printf(" kuti");
	}

	if (num / 100000)
	{
		Bangla(num / 100000);
		num %= 100000;
		printf(" lakh");
	}
	
	if (num / 1000)
	{
		Bangla(num / 1000);
		num %= 1000;
		printf(" hajar");
	}

	if (num / 100)
	{
		Bangla(num / 100);
		num %= 100;
		printf(" shata");
	}

	if (num)
	printf(" %lld", num);
}