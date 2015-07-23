/*
利用窮舉法更改第一列(因為2可以根據1做塗色、3根據2、4根據3、5根據4)，
而其餘列則要根據上一列作變更，
最後來觀察第五行是否有達到題目的要求，藉此來判斷此組填色方式是否可行
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