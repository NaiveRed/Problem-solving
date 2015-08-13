/*

把σ : https://zh.wikipedia.org/zh-tw/つ计

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
		岿碭Ω"崩代":
		狦琌タ俱计眔场舱埃が借τ虫ノ y++ 琌⊿快猭―眔场舱
		┮眖秨﹍碞ㄏノ y += 2ㄏウ1案计1计耞gcd程ノ(na, nb, nc)眔ぃ舱
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

			for (int i = 1; c*i <= num; i++)//狦 (a, b, c) 琌つ计ウタ俱计计琌つ计 (na, nb, nc) 琌つ计
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