#include<cstdio>
#include<queue>
#include<list>
#include<unordered_map>
using namespace std;


int BFS(int start, int TTL, unordered_map<int, list<int>>& adjList);
int main()
{
	int set, Case(1);

	while (scanf("%d", &set) && set)
	{
		unordered_map<int, list<int>> adjList;

		while (set--)
		{
			int x, y;
			scanf("%d%d", &x, &y);

			adjList[x].push_back(y);
			adjList[y].push_back(x);

		}

		int start, TTL;

		while (scanf("%d%d", &start, &TTL) && (start || TTL))
			printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n", Case++, BFS(start, TTL, adjList), start, TTL);

		getchar();
	}

return 0;
}
int BFS(int start, int TTL, unordered_map<int, list<int>>& adjList)
{

	queue<int> Queue;
	unordered_map<int, bool> visit;
	unordered_map<int, int> dp;

	for (unordered_map<int, list<int>>::iterator it = adjList.begin(); it != adjList.end(); it++)
		visit[it->first] = false;

	Queue.push(start);
	dp[start] = 0;

	int count(0);
	while (!Queue.empty())
	{
		int front = Queue.front();
		if (dp[front] > TTL)
			break;
		Queue.pop();
		visit[front] = true;
		count++;

		for (list<int>::iterator it = adjList[front].begin(); it != adjList[front].end(); it++)
		{
			if (!visit[*it])
			{
				Queue.push(*it);
				visit[*it] = true;
				dp[*it] = dp[front] + 1;
			}
		}

	}

	return visit.size() - count;
}