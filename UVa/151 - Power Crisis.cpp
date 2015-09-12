#include<cstdio>

int Josephus(int n);
int main()
{
	inline int input();

	int n;
	while (n = input())
		printf("%d\n", Josephus(n-1));//因為第一個人直接刪去，所以 n - 1

	return 0;
}
int input()
{
	int num(0);
	char c;

	while ((c = getchar()) != '\n')
		num = num * 10 + c - '0';

	return num;
}
int Josephus(int n)
{
	/*
	全部號碼減一，從0開始，第13為12，而第一個在一開始就被刪去，再減一，所以發電廠為11
	*/
	int m;
	for (m = 1;; m++)
	{
		/*
		Josephus Problem:
		f(n, m) = (f(n-1, m) + m) % n;
		f(1, m) = 0;
		*/
		int ans(0);
		for (int i = 2; i <= n; i++)
			ans = (ans + m) % i;

		if (ans == 11)
			break;
	}

	return m;
}
