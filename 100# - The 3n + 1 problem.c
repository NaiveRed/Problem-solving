#include<stdio.h>


unsigned long F(unsigned long n, unsigned long k);

int main(void){

	unsigned long i, j, a, b, count, length, max;

	max = 0;

	while (scanf("%lu %lu", &i, &j) == 2)
	{
		if (i < j)
		{
			a = j;
			b = i;
		}
		else{
			a = i;
			b = j;
		}

		max = 0;
		for (count = b; count <= a; count++)
		{

			length = F(count, 1);

			if (length > max)
				max = length;

		}

		printf("%lu %lu %lu\n", i, j, max);
	}
	return 0;
}

unsigned long F(unsigned long n, unsigned long k){


	if (n == 1)
		return k;

	else if (n % 2 == 0)
	{
		n = n / 2;
		k++;
		return F(n, k);
	}
	else if (n % 2 == 1)
	{
		n = 3 * n + 1;
		k++;
		return F(n, k);
	}

}