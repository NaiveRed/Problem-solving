#include<cstdio>

int printBinary(int n);//return the quantity of 1s
int main()
{
	int num;
	while (scanf("%d", &num) && num)
	{
		printf("The parity of ");
		int parity = printBinary(num);
		printf(" is %d (mod 2).\n", parity);
	}

	return 0;
}
int printBinary(int n)
{
	char binary[50]{};
	int idx = 0, count = 0;

	while (n)
	{
		if (n & 1)
		{
			binary[idx++] = '1';
			count++;
		}
		else
			binary[idx++] = '0';

		n /= 2;
	}

	for (int i = idx - 1; i >= 0; i--)
		putchar(binary[i]);

	return count;
}