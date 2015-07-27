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
				printer.pop();//���ެO���O�n�C�L����pop

				bool canPrint(true);
				for (int i = front.priority + 1; i < 10; i++)
					canPrint &= (priority[i] == 0);//�ˬdqueue�W�O�_����ۤv�u���װ����s�b

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
				else printer.push(front);//�p�G����L�X�N���queue�̫�
			}

		}

	}

	return 0;
}