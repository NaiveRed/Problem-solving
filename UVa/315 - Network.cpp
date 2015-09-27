#include<cstdio>
#include<list>
#include<algorithm>
#define N 105
#define EOL -1
#define SUCCESS -2

std::list<int> adj[N];
int dfn[N], low[N], times, ap;

inline int input(int& num);
void DFS(int p, int i);
int main()
{
	int line, i;
	while (input(line) && line)
	{
		//init
		ap = times = 0;
		std::fill(dfn, dfn + N, 0);
		std::fill(low, low + N, 0);
		for (i = 0; i < N; i++)
			adj[i].clear();

		int node1, node2, end;
		while (input(node1) && node1)//不管有沒有達到n行，最後都會有0
			while (end = input(node2))
			{
			adj[node1].push_back(node2);
			adj[node2].push_back(node1);
			if (end == EOL)
				break;
			}

		for (i = 1; i <= line; i++)
			if (!dfn[i])
				DFS(i, i);

		printf("%d\n", ap);

	}



	return 0;
}
int input(int& num)
{
	char c;
	num = 0;

	while ((c = getchar()) != ' ')
	{
		if (c == '\n')
			return EOL;//End-Of-Line
		num = num * 10 + c - '0';
	}

	return SUCCESS;

}
void DFS(int p, int i)
{
	int child(0);
	bool isAP(false);

	dfn[i] = low[i] = ++times;

	for (std::list<int>::iterator it = adj[i].begin(); it != adj[i].end(); it++)//p為*it的祖父: p -> i -> *it
	{
		if (*it != p)//避免回頭路
		{
			if (dfn[*it])//back-edge 
				low[i] = std::min(low[i], dfn[*it]);//遍歷順序小的是祖先
			else//tree-edge
			{
				child++;
				DFS(i, *it);

				//遍歷順序小的是祖先
				low[i] = std::min(low[i], low[*it]);

				if (low[*it] >= dfn[i])//代表底下沒有edge-back可以走(等號代表走到那個back-edge的點
					isAP = true;

			}
		}
	}

	/*
	1.根，要由子節點數量判斷是否為AP
	2.不是根
	*/
	if ((i == p&&child > 1) || (i != p&&isAP))
		ap++;
}