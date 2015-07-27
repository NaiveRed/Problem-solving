#include<stdio.h>

int main(){

	unsigned int a, b;

	while (scanf("%u %u", &a, &b) != EOF)
	{
		if (!a&&!b)
			break;

		unsigned int count = 0, temp, carry = 0;

		while (a || b)
		{
			temp = (a % 10) + (b % 10) + carry;//兩數的最後一位相加再加上有無進一位

			carry = 0;

			if (temp >= 10)
			{
				count++;
				carry = 1;
			}

			a /= 10;
			b /= 10;
		}

		if (count == 1)
			printf("%u carry operation.\n", count);
		else if (count)
			printf("%u carry operations.\n", count);
		else
			printf("No carry operation.\n");

	}

	return 0;
}