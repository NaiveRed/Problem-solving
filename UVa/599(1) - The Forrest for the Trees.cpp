#include <cstdio>
#include <stack>
#define LEN 26

int adj_list[26][27]; //[][26] for len
bool visited[26];
int all[27]; //[26]: number of points
int dfs()	//return the number of trees
{
	if (!all[LEN])
		return 0;

	std::stack<int> s;
	int tree = 0, remain = all[LEN];

	for (int i = 0; i < all[LEN]; i++)
	{
		int start = all[i];
		if (visited[start])
			continue;

		s.push(start);
		visited[start] = true;
		remain--;
		while (!s.empty())
		{
			int now = s.top();
			s.pop();
			for (int j = 0; j < adj_list[now][LEN]; j++)
			{
				int next = adj_list[now][j];
				if (!visited[next])
				{
					visited[next] = true;
					s.push(next);
					remain--;
				}
			}
		}

		tree++;
		if (remain && remain <= 3) //剩三個點時一定是一棵樹
		{
			tree++;
			break;
		}
	}

	return tree;
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
		while (true)
		{
			fgets(input, 60, stdin);
			if (input[0] != '*')
			{
				int u = input[1] - 'A';
				int v = input[3] - 'A';
				adj_list[u][adj_list[u][LEN]++] = v;
				adj_list[v][adj_list[v][LEN]++] = u;
			}
			else //****
				break;
		}

		fgets(input, 60, stdin);

		int acorn = 0;
		for (int i = 0; input[i]; i += 2)
		{
			int idx = input[i] - 'A';
			if (adj_list[idx][LEN])
				all[all[LEN]++] = idx;
			else //no any edge
				acorn++;
		}

		int tree = dfs();
		printf("There are %d tree(s) and %d acorn(s).\n", tree, acorn);

		//init
		all[LEN] = 0;
		for (int i = 0; i < 26; i++)
			visited[i] = false;
		for (int i = 0; i < 26; i++)
			adj_list[i][LEN] = 0;
	}

	return 0;
}