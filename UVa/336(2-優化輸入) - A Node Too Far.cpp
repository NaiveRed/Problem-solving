#include<cstdio>
#include<queue>
#include<list>
#include<unordered_map>
using namespace std;

int BFS(int start, int TTL, list<int>* adjList);
inline int input();
int main()
{
	int set, Case(1);

	while (set = input())
	{
		unordered_map<int, int> id;
		list<int> adjList[31];
		int size(0);

		while (set--)
		{
			int x = input(), y = input();
			
			//幫數字編號從1開始，0就是還沒編過，就為目前數量+1
			if (!id[x])
			{
				id[x] = ++size;
				x = size;
			}
			else
				x = id[x];

			if (!id[y])
			{
				id[y] = ++size;
				y = size;
			}
			else
				y = id[y];

			adjList[x].push_back(y);
			adjList[y].push_back(x);

		}

		int start, TTL;

		while (scanf("%d%d", &start, &TTL) && (start || TTL))
			printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n", Case++, size - BFS(id[start], TTL,  adjList), start, TTL);

		getchar();
	}

	return 0;
}
int BFS(int start, int TTL,  list<int>* adjList)
{

	queue<int> Queue;
	bool visit[31]{false};
	int dp[31];//用來計算當前的層數，以判斷是否已達TTL

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

	return count;
}
int input()
{
	char c = getchar();
	while (c > '9'||c < '0')
		c = getchar();

	int num(c - '0');

	while ((c = getchar()) <= '9'&&c >= '0')
		num = num * 10 + c - '0';

	return num;
}