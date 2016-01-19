#include<stdio.h>
#include<stdbool.h>
#define MIN(a,b) ((a)<(b)?(a):(b))

int main()
{
	char square[101][101];
	int Case;
	scanf("%d", &Case);

	while (Case--)
	{
		int M, N, Q;

		scanf("%d%d%d", &M, &N, &Q);
		int i, j;
		for (i = 0; i < M; i++)
		{
			getchar();
			for (j = 0; j < N; j++)
				square[i][j] = getchar();
		}

		printf("%d %d %d\n", M, N, Q);

		int r, c;
		while (Q--)
		{
			scanf("%d%d", &r, &c);

			char temp = square[r][c];
			int length;
			bool flag = true;

			//¤@°é¤@°éÀË¬d
			for (length = 1; r + length < M&&r - length >= 0 && c + length < N&&c - length >= 0; length++)
			{
				//r+length ~ r-length¡Bc+length ~ c-length
				for (i = length; i + length>=0; i--)
				{
					if (square[r - length][c + i] != temp || square[r + length][c + i] != temp || square[r + i][c - length] != temp || square[r + i][c + length] != temp)
					{
						flag = false;
						break;
					}
				}

				if (!flag)
					break;
			}

			length--;
			printf("%d\n", 2 * length + 1);
		}
	}

	return 0;
}