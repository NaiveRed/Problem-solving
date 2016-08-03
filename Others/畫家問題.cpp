/*
编程题＃1： 画家问题

来源: POJ 1681 (Coursera声明：在POJ上完成的习题将不会计入Coursera的最后成绩。)

注意： 总时间限制: 1000ms 内存限制: 65536kB

描述

有一个正方形的墙，由N*N个正方形的砖组成，其中一些砖是白色的，另外一些砖是黄色的。Bob是个画家，想把全部的砖都涂成黄色。但他的画笔不好使。当他用画笔涂画第(i, j)个位置的砖时， 位置(i-1, j)、 (i+1, j)、 (i, j-1)、 (i, j+1)上的砖都会改变颜色。请你帮助Bob计算出最少需要涂画多少块砖，才能使所有砖的颜色都变成黄色。

输入

第一行是个整数t(1≤t ≤20)，表示要测试的案例数。然后是t个案例。每个案例的首行是一个整数n (1≤n ≤15)，表示墙的大小。接下来的n行表示墙的初始状态。每一行包含n个字符。第i行的第j个字符表示位于位置(i,j)上的砖的颜色。“w”表示白砖，“y”表示黄砖。

输出

每个案例输出一行。如果Bob能够将所有的砖都涂成黄色，则输出最少需要涂画的砖数，否则输出“inf”。

样例输入

2
3
yyy
yyy
yyy
5
wwwww
wwwww
wwwww
wwwww
wwwww
样例输出

0
15 

利用窮舉法更改第一列(因為2可以根據1做塗色、3根據2、4根據3、5根據4)，
除了第一列，要根據上一列作變更，
最後來觀察第五列是否有達到題目的要求，藉此來判斷此組填色方式是否可行
*/
#include<cstdio>
#include<cstring>
#define N 17

int wall[N][N];
int paint[N][N];
bool guess(int border);
bool enumerate(int border);
int main()
{
	int test;
	while (scanf("%d", &test) != EOF)
	{
		while (test--)
		{
			int n;
			char temp;
			scanf("%d", &n);


			for (int y = 1; y <= n; y++)
				for (int x = 1; x <= n; x++)
				{
				temp = getchar();
				if (temp == '\n')
					temp = getchar();
				wall[y][x] = temp == 'w' ? 0 : 1;
				}

			bool ans(enumerate(n));
			
			if (ans)
			{
				int count(0);
				for (int y = 1; y <= n; y++)
				{
					for (int x = 1; x <= n; x++)
						count += paint[y][x];
				}
				printf("%d\n", count);
			}
			else puts("inf");

			memset(paint, NULL, N*N);
			memset(wall, NULL, N*N);
	}

}

return 0;
}
bool guess(int border)
{

	for (int y = 2; y <= border; y++)
		for (int x = 1; x <= border; x++)
			paint[y][x] = !((wall[y - 1][x] + paint[y - 1][x] + paint[y - 1][x + 1] + paint[y - 1][x - 1] + paint[y - 2][x]) & 1);

	for (int x = 1; x <= border; x++)
		if (!((wall[border][x] + paint[border][x] + paint[border][x - 1] + paint[border][x + 1] + paint[border - 1][x]) & 1))
			return false;

	return true;
}
bool enumerate(int border)
{
	while (!(guess(border)))
	{
		paint[1][1]++;
		int x(1);
		bool bp(true);
		while (paint[1][x] > 1)
		{
			paint[1][x] = 0;
			if (x + 1 > border)
			{
				bp = false;
				break;
			}
			paint[1][++x]++;

		}

		if (!bp)
			return false;
	}

	return true;
}
