#include <cstdio>
#include <cstring>
#include <cctype>

const int dir[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
char map[50][52];
int n, m;
inline bool in_border(int x, int y)
{
	return x >= 0 && x < n && y >= 0 && y < m;
}
bool find(int x, int y, char *tar, int d)
{
	int idx = 0;
	while (tar[idx])
	{
		if (map[x][y] != tar[idx])
			break;

		idx++;
		x += dir[d][0];
		y += dir[d][1];
		if (!in_border(x, y))
			break;
	}

	return tar[idx] == '\0';
}
int main()
{
	int T;
	char tar[52];
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d ", &n, &m);
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
				map[i][j] = tolower(getchar());
			getchar();
		}

		int k;
		scanf("%d ", &k);

		for (int i = 0; i < k; i++)
		{
			bool ok = false;
			int j = 0;
			char c;
			while ((c = getchar()) != '\n' && c != EOF)
				tar[j++] = tolower(c);
			tar[j++] = '\0';

			for (int x = 0; x < n && !ok; x++)
				for (int y = 0; y < m && !ok; y++)
					for (int d = 0; d < 8; d++)
						if (find(x, y, tar, d))
						{
							printf("%d %d\n", x + 1, y + 1);
							ok = true;
							break;
						}
		}

		if (T)
			putchar('\n');
	}

	return 0;
}
