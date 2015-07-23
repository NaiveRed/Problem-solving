/*
�Q�νa�|�k���Ĥ@�C(�]��2�i�H�ھ�1�����B3�ھ�2�B4�ھ�3�B5�ھ�4)�A
�Ө�l�C�h�n�ھڤW�@�C�@�ܧ�A
�̫���[��Ĥ���O�_���F���D�ت��n�D�A�Ǧ��ӧP�_���ն��覡�O�_�i��
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