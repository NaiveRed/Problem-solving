/*
time: 0.255s
*/
#include<stdio.h>
#include<limits.h>
int length[1000000] = { 0, 1 };

int countLength(long long n);
int main()
{
	int i = 1;

	for (; i < 1000000; i++)
	{
		if (i % 2 == 0)
			length[i] = 1 + length[i >> 1];// i >> 1 = i / 2

		else if (i % 8 == 5)
			length[i] = 4 + length[3 * ((i - 5) >> 3) + 2];// n >> 3  = n / 8
		/*
		if i = 8j + 5   ->   i is odd
		follow the pattern:
		8j + 5 -> 24j + 16 -> 12j + 8 -> 6j + 4 -> 3j + 2
		1 odd     2 even      3 even     4 even
		length[i]=4 + length[3 * j + 2]  (j = (i - 5)/8)
		*/
		else
			length[i] = countLength(i);
	}

	int a, b;
	while (scanf("%d%d", &a, &b) != EOF)
	{
		int small = a, big = b;
		if (a > b)
		{
			small = b;
			big = a;
		}

		int max = 0;

		for (; small <= big; small++)
			max = max > length[small] ? max : length[small];

		printf("%d %d %d\n", a, b, max);
	}

	return 0;
}
int countLength(long long n)
{
	int count = 1;

	while (n != 1)
	{

		if (n & 1)
			n += (n << 1) + 1;// n = n + 2n + 1
		else n >>= 1;

		if (n > INT_MAX)
			return 0;

		count++;
	}

	return count;
}