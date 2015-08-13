/*

�i�Ѧ� : https://zh.wikipedia.org/zh-tw/�ĪѼ�

*/
#include<cstdio>
#include<algorithm>
#include<cmath>
#define N 1000001

bool use[N];

inline int input();
inline int gcd(int a, int b);
int main()
{

	int num;
	while ((num = input()) != EOF)
	{
	
		int coprime(0), notUse(0);

		/*
		���F�X����"����":
		�p�G�O������ƭ����A�i�H�o������զX�A���F���誺�A�ӳ�� y++ �O�S��k�D�o�����զX���A
		�ҥH�q�@�}�l�A�N�ϥ� y += 2�A�ϥ���1�Ӱ��ơB1�ө_�ơA�P�_gcd�A�̫�A�Q��(na, nb, nc)���o���P�զX�C
		*/

		for (int x = 1; x < sqrt(num); x++)
			for (int y = x + 1;; y += 2)
			{
			int c(x*x + y*y);

			if (c > num)
				break;

			if (gcd(x, y) != 1)
				continue;

			int a(y*y - x*x), b(x*y << 1);

			coprime++;

			for (int i = 1; c*i <= num; i++)//�p�G (a, b, c) �O�ĪѼơA���̪�����ƭ��ơA�]�O�ĪѼơA�Y (na, nb, nc) �]�O�ĪѼơC
				use[a*i] = use[b*i] = use[c*i] = true;
			
			}

		for (int i = 1; i <=num; i++)
			if (!use[i])
				notUse++;

		printf("%d %d\n", coprime, notUse);

		std::fill(use, use + num, false);

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
int gcd(int a, int b)
{
	while (b)
	{
		int temp(b);
		b = a%b;
		a = temp;
	}

	return a;
}