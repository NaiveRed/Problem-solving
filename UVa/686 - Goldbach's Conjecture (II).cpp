#include<cstdio>
#define N 32769

bool notPrime[N]{true,true};

void getPrime();
int input();
int main()
{

	getPrime();

	int num;

	while (num = input())
	{
		int count(0);
		for (int i = 2; i <= num >> 1; i++)
		{
			if (notPrime[i])
				continue;

			if (!notPrime[num - i])
				count++;
		}

		printf("%d\n", count);
	}

	return 0;
}
int input()
{
	char c;
	int num(0);
	while ((c = getchar()) != '\n')
		num = num * 10 + c - '0';

	return num;
}
void getPrime()
{
	for (int i = 2; i < N; i++)
	{
		if (!notPrime[i])
			for (int j = i<<1; j < N; j += i)
				notPrime[j] = true;
	}
}