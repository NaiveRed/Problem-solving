#include <cstdio>
#include <cstring>
#define N 26

int main()
{
	//freopen("test.in", "r", stdin);
	//freopen("test.out", "w", stdout);
	int T;
	scanf("%d ", &T);

	char input[60];
	while (T--)
	{
		//init
		int union_count = 0; //合併次數
		int not_acorn_count = 0;
		bool not_acorn[N] = {};

		while (true)
		{
			fgets(input, 60, stdin);
			if (input[0] != '*')
			{
				int u = input[1] - 'A', v = input[3] - 'A';
				union_count++;
				if (!not_acorn[u])
				{
					not_acorn[u] = true;
					not_acorn_count++;
				}
				if (!not_acorn[v])
				{
					not_acorn[v] = true;
					not_acorn_count++;
				}
			}
			else //****
				break;
		}

		fgets(input, 60, stdin);

		int all = strlen(input) / 2;
		int acorn = all - not_acorn_count;
		int tree = all - union_count - acorn;
		printf("There are %d tree(s) and %d acorn(s).\n", tree, acorn);
	}

	return 0;
}