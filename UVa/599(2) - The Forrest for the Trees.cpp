#include <cstdio>
#include <cstring>
#define N 26

int tree[N];	 //所屬的樹編號
int union_count; //合併次數
inline void do_union(int u, int v)
{
	if (tree[u] == tree[v])
		return;

	union_count++;
	int id_u = tree[u], id_v = tree[v];
	for (int i = 0; i < N; i++)
		if (tree[i] == id_u)
			tree[i] = id_v;
}
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
		bool is_acorn[N];
		for (int i = 0; i < N; i++)
			tree[i] = i;
		for (int i = 0; i < N; i++)
			is_acorn[i] = true;
		union_count = 0;

		while (true)
		{
			fgets(input, 60, stdin);
			if (input[0] != '*')
			{
				int u = input[1] - 'A', v = input[3] - 'A';
				do_union(u, v);
				if (is_acorn[u])
					is_acorn[u] = false;
				if (is_acorn[v])
					is_acorn[v] = false;
			}
			else //****
				break;
		}

		fgets(input, 60, stdin);

		int all = strlen(input) / 2, acorn=0;
		for (int i = 0; input[i]; i += 2)
			if (is_acorn[input[i] - 'A'])
				acorn++;

		int tree = all - union_count - acorn;
		printf("There are %d tree(s) and %d acorn(s).\n", tree, acorn);
	}

	return 0;
}