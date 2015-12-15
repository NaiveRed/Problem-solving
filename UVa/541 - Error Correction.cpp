#include<cstdio>

int main()
{
	bool row[101] = {}, col[101] = {};//true if this row or column is odd
	char c;
	int N;
	while (scanf("%d", &N) && N)
	{
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++)
			{
			getchar();
			c = getchar();
			row[i] ^= c - '0';//XOR
			col[j] ^= c - '0';
			}

		bool ans = true;
		int r = 0;
		for (int i = 1; i <= N; i++)
			if (row[i])
			{
			if (r)//���u1�C�ݭn�ק�
			{
				ans = false;
				break;
			}
			r = i;
			}

		int c = 0;
		for (int i = 1; i <= N; i++)
			if (col[i])
			{
			if (c)//���u1��ݭn�ק�
			{
				ans = false;
				break;
			}
			c = i;
			}

		if (!ans)
			puts("Corrupt");
		else if (!r&&!c)
			puts("OK");
		else if (r&&c)//��C���n�����X���~�i�H��
			printf("Change bit (%d,%d)\n", r, c);
		else// (r&&!c) || (!r&&c)
			puts("Corrupt");

		//init
		for (int i = 1; i <= N; i++)
			row[i] = col[i] = false;

	}

	return 0;
}