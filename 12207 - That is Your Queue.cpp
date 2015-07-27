#include<cstdio>
#include<deque>

int main()
{

	int num, test, case_num(1);

	while (scanf("%d%d", &num, &test) && (num || test))
	{
		std::deque<int> people;
		char command;

		/*
		測資十分大，如果全部push進去會TL。
		如果超過1000，代表沒辦法直接用 N 出來，一定要E x 再 N，所以在 E 時push_front即可。
		*/
		if (num <= 1000)
			for (int i = 1; i <= num; i++)
				people.push_back(i);
		else
		{
			for (int i = 1; i <= 1000; i++)
				people.push_back(i);
		}

			printf("Case %d:\n", case_num++);

		for (int i = 0; i < test; i++)
		{
			getchar();
			scanf("%c", &command);

			int id;
			if (command == 'N')
			{
				id = people.front();
				people.push_back(id);
				people.pop_front();

				printf("%d\n", id);
			}
			else
			{
				scanf("%d", &id);
				for (auto it = people.begin(); it != people.end(); it++)
				{
					if (*it == id)
					{
						people.erase(it);
						break;
					}
				}
				people.push_front(id);
			}
		}
	}

	return 0;
}