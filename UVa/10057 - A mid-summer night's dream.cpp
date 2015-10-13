#include<cstdio>

int input();
int getMid(int n, int *num);
int main()
{

	int Case;

	while ((Case=input()) != EOF)
	{
		int num[65537]{0};

		for (int i = 0; i < Case; i++)
		{
			int temp;
			temp = input();
			num[temp]++;
		}


		int mid, amount, diff;

		if (Case & 1)
		{
			mid = getMid((Case >> 1)+1, num);
			amount = num[mid];
			diff = 1;
		}
		else
		{
			mid = getMid(Case >> 1, num);
			amount = num[mid];
			diff = 1;

			int next = getMid((Case >> 1) +1,num);

			/*
			ex.2 3 8 10
			
			2 3     8  10

			1. (3-2)+(8-3)+(10-3)
			2. (8-2)+(8-3)+(10-8)

			(3-2)+(10-3)=(8-2)+(10-8)
			
			diff=3,4,5,6,7,8
			*/
			if (next != mid)
			{
				amount += num[next];
				diff = next - mid + 1;//有那些數可以(不用在輸入的那些裡)
			}
		}

		printf("%d %d %d\n", mid, amount, diff);

	}


	return 0;
}
int input()
{
	int num(0);

	char c;

	while ((c = getchar()) != '\n')
	{
		if (c == EOF)
			return EOF;
		num = num * 10 + c - '0';
	}

	return num;
}
int getMid(int n, int *num)
{
	int sum(0), i;

	for (i = 0;;i++)
	{
		if (num[i])
			sum += num[i];
		if (sum >= n)
			break;
	}

	return i;
}