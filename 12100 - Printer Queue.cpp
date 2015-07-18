#include<cstdio>
#include<queue>

int main()
{
	int test;

	int n, tar;

	struct PrintData
	{
		int priority;
		int pos;
	};

	while (scanf("%d", &test) != EOF)
	{
		while (test--)
		{
			scanf("%d%d", &n, &tar);

			int temp, priority[10]{0};

			std::queue<PrintData> printer;

			for (int i = 0; i < n; i++)
			{
				scanf("%d", &temp);
				priority[temp]++;
				printer.push({ temp, i });
			}

			int time(0);
			while (true)
			{
				PrintData front(printer.front());
				printer.pop();//不管是不是要列印都需pop

				bool canPrint(true);
				for (int i = front.priority + 1; i < 10; i++)
					canPrint &= (priority[i] == 0);//檢查queue上是否有比自己優先度高的存在

				if (canPrint)
				{
					time++;
					priority[front.priority]--;

					if (front.pos == tar)
					{
						printf("%d\n", time);
						break;
					}
				}
				else printer.push(front);//如果不能印出就放到queue最後
			}

		}

	}

	return 0;
}