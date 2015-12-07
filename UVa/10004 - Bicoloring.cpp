#include<cstdio>
#include<list>
#include<algorithm>
using namespace std;

list<int> adjList[200];
bool color[200], isVisit[200], ans;

void dfs(int n);
int main()
{
	int node;
	while (scanf("%d", &node) && node)
	{
		//init
		fill(color, color + node, false);
		fill(isVisit, isVisit + node, false);
		for (int i = 0; i < node; i++)
			adjList[i].clear();
		ans = true;

		int edge;
		scanf("%d", &edge);
		int a, b;
		while (edge--)
		{
			scanf("%d%d", &a, &b);
			adjList[a].push_back(b);
			adjList[b].push_back(a);
		}
		dfs(0);
		puts(ans ? "BICOLORABLE." : "NOT BICOLORABLE.");
	}

	return 0;
}
void dfs(int n)
{
	isVisit[n] = true;
	for (int v : adjList[n])
		if (!isVisit[v])
		{
		color[v] = !color[n];
		dfs(v);
		}
		else if (color[v] == color[n])
		{
			ans = false;
			return;
		}
}