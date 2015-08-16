#include<cstdio>
#define N 100000

int prime[N];
bool sieve[N]{true, true};

inline int input();
inline void getPrime();
int main()
{
	getPrime();

	int num;

	while (num = input())
	{
		bool first(true);

		if (num < 0)
		{
			printf("%d = -1", num);
			first = false;
			num *= -1;
		}
		else
			printf("%d =", num);

		//µu°£ªk
		for (int j = 0; prime[j] <= num&&prime[j]; j++)
		{
			while (!(num%prime[j]))
			{	
				num /= prime[j];

				if (first)
				{
					first = false;
					printf(" %d", prime[j]);
				}
				else printf(" x %d", prime[j]);

			}

		}
		
		if (num!=1)
			printf("%s%d",first?" ":" x ", num);

		putchar('\n');
	}

	return 0;
}
int input()
{

	char c;
	int num(0);
	bool neg(false);

	while ((c = getchar()) != ' '&&c != '\n')
	{
		if (c == '-')
		{
			neg = true;
			continue;
		}

		num = num * 10 + c - '0';
	}

	return neg ? num*(-1) : num;
}
void getPrime()
{
	int count(0);
	for (int i = 2; i < N; i++)
	{
		if (!sieve[i])
			prime[count++] = i;

		for (int j = 0; prime[j] * i < N; j++)
		{
			sieve[prime[j] * i] = true;
			if (!(i%prime[j]))
				break;
		}
	}

}
