#include<cstdio>

int Josephus(int n);
int main()
{
	inline int input();

	int n;
	while (n = input())
		printf("%d\n", Josephus(n-1));//�]���Ĥ@�ӤH�����R�h�A�ҥH n - 1

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
	�������X��@�A�q0�}�l�A��13��12�A�ӲĤ@�Ӧb�@�}�l�N�Q�R�h�A�A��@�A�ҥH�o�q�t��11
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
