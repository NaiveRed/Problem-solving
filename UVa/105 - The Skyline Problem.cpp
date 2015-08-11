#include<cstdio>
#define N 10001

int height[N];

int input();
int main()
{
	int l, h, r;
	int border(0);
	while ((l = input())!=EOF)
	{
		h = input();
		r = input();

		for (int i = l; i < r; i++)//最右側已經不屬於它了，只是邊界
			height[i] = height[i] > h ? height[i] : h;

		border = border > r ? border : r;
	}

	int last(0);
	for (int now = 0; now < border; now++)
	{
		if (height[now] != last)
		{
			printf("%d %d ", now, height[now]);
			last = height[now];
		}
	}

	printf("%d %d\n", border, 0);

	return 0;
}
int input()
{
	char c;
	int num(0);
	while ((c = getchar()) != ' '&&c != '\n')
	{
		if (c == EOF)
			return EOF;

		num = num * 10 + c - '0';
	}

	return num;
}