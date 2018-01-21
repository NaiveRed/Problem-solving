//Topological Ordering
#include <cstdio>
#include <cstring>
#define N 26

int all_var[21], all;
int adj_list[N][21], list_len[N], ref[N];
int ans[N];

void backtracking(int len)
{
	if (len == all)
	{
		for (int i = 0; i < all; i++)
			putchar('a' + ans[i]);
		putchar('\n');
	}
	else
	{
		for (int i = 0; i < all; i++)
		{
			if (ref[all_var[i]])
				continue;
			int c = all_var[i];
			ans[len] = c;

			ref[c] = 1000; //used
			for (int j = 0; j < list_len[c]; j++)
				ref[adj_list[c][j]]--;

			backtracking(len + 1);

			ref[c] = 0;
			for (int j = 0; j < list_len[c]; j++)
				ref[adj_list[c][j]]++;
		}
	}
}
int main()
{
	//freopen("test.in", "r", stdin);
	//freopen("test.out", "w", stdout);
	bool first = true;
	char str[105];
	while (fgets(str, 105, stdin))
	{
		int i;
		bool use[N] = {};
		for (i = 0; str[i]; i += 2)
			use[str[i] - 'a'] = true;

		//lexicographical
		for (i = 0; i < N; i++)
			if (use[i])
				all_var[all++] = i;

		fgets(str, 105, stdin);
		int len = strlen(str);
		for (i = 0; i < len; i += 4)
		{
			int u = str[i] - 'a', v = str[i + 2] - 'a';
			adj_list[u][list_len[u]++] = v; //u -> v
			ref[v]++;
		}

		if (!first)
			putchar('\n');
		else
			first = false;
		backtracking(0);

		//init
		all = 0;
		for (int i = 0; i < N; i++)
			ref[i] = list_len[i] = 0;
	}

	return 0;
}