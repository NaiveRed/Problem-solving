#include<cstdio>
#include<list>
#define TO_INT(c) ((c)-'A')
using namespace std;

list<char> graph[26];
bool isVisit[26];

void dfs(int n);
int main()
{
	bool first = true;
	int Case;
	scanf("%d", &Case);
	getchar();
	getchar();

	while (Case--)
	{
		char edge[5];
		gets(edge);

		int node = TO_INT(edge[0]) + 1;

		while (gets(edge) && edge[0])
		{
			graph[TO_INT(edge[0])].push_back(edge[1]);
			graph[TO_INT(edge[1])].push_back(edge[0]);
		}

		//dfs and count for connected
		int count = 0;
		for (int i = 0; i < node; i++)
		{
			if (!isVisit[i])
			{
				count++;
				dfs(i);
			}
		}

		if (first)
		{
			first = false;
			printf("%d\n", count);
		}
		else
			printf("\n%d\n", count);

		//init
		for (int i = 0; i < node; i++)
		{
			graph[i].clear();
			isVisit[i] = false;
		}
	}

	return 0;
}
void dfs(int n)
{
	isVisit[n] = true;

	for (char c : graph[n])
	{
		int idx = TO_INT(c);
		if (!isVisit[idx])
			dfs(idx);
	}
}