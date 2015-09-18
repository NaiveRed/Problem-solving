#include<cstdio>
#include<queue>
#include<list>
#include<unordered_map>
using namespace std;


int BFS(int start, int TTL, unordered_map<int,int>& id, list<int>* adjList);
int main()
{
	int set, Case(1);

	while (scanf("%d", &set) && set)
	{
		unordered_map<int, int> id;
		list<int> adjList[31];
		int size(0);

		while (set--)
		{
			int x, y;
			scanf("%d%d", &x, &y);

			//���Ʀr�s���q1�}�l�A0�N�O�٨S�s�L�A�N���ثe�ƶq+1
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
			printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n", Case++, size-BFS(start, TTL,id, adjList), start, TTL);

		getchar();
	}

	return 0;
}
int BFS(int start, int TTL, unordered_map<int, int>& id, list<int>* adjList)
{

	queue<int> Queue;
	bool visit[31]{false};
	int dp[31];//�Ψӭp���e���h�ơA�H�P�_�O�_�w�FTTL
	
	start = id[start];
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