#include<cstdio>
#include<queue>
#include<stack>

int main()
{
	std::stack<int> sta;
	std::queue<int> que;
	std::priority_queue<int> pque;

	int com_num;
	while (scanf("%d", &com_num) != EOF)
	{
		
		int command, num;

		bool isStack(true), isQueue(true), isPriQueue(true);

		while (com_num--)
		{
			scanf("%d%d", &command, &num);

			if (command == 1)
			{
				sta.emplace(num);
				que.emplace(num);
				pque.emplace(num);
			}
			else
			{
				if (sta.empty() || sta.top() != num)
					isStack = false;
				if (!sta.empty()) sta.pop();

				if (que.empty() || que.front() != num)
					isQueue = false;
				if (!que.empty()) que.pop();

				if (pque.empty() || pque.top() != num)
					isPriQueue = false;
				if (!pque.empty()) pque.pop();

			}
		}

		if (isStack + isQueue + isPriQueue > 1)
			puts("not sure");
		else if (isStack)
			puts("stack");
		else if (isQueue)
			puts("queue");
		else if (isPriQueue)
			puts("priority queue");
		else puts("impossible");

		while (!sta.empty())
			sta.pop();
		while (!que.empty()) 
			que.pop();
		while (!pque.empty()) 
			pque.pop();
	}

	return 0;
}
