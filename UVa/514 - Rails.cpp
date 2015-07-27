#include<cstdio>
#include<stack>
#define N 1001

int main()
{
	int n, car[N] = { 0 };
	std::stack<int> station;

	while (scanf("%d", &n) && n)
	{

		while (scanf("%d", &car[1]) && car[1])
		{
			for (int i = 2; i <= n; i++)
				scanf("%d", &car[i]);

			int target(1), index(1);
			bool ans(true);

			while (index <= n)
			{
				if (target < car[index])//如果目前的車廂小於欲排列的順序，就先放進stack中
					station.push(target++);
				else if (target == car[index])//相等的話，車廂就直接過去了
				{
					target++;
					index++;
				}
				else 
				{	
					if (station.top() != car[index])//既不相等也不小於，那剩下的操作就是pop出stack中的車廂了
					{
						ans = false;
						break;
					}

					station.pop();
					index++;
				}
			}
			
			printf("%s\n", ans ? "Yes" : "No");
		}

		
		for (int i = 0; i <= n; i++)
			car[i] = 0;

		puts("");
	}

	return 0;
}