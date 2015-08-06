#include<cstdio>
#include<algorithm>

using namespace std;
int main()
{
	struct Data{
		int id;
		int AC_num;
		int penalty_time;
	};


	int Case;
	bool first(true);

	scanf("%d", &Case);
	getchar();
	getchar();

	while (Case--)
	{
		if (first)
			first = false;
		else putchar('\n');

		int id, problem, time;
		char L, temp;

		Data data[101]{};
		bool AC[101][10]{};
		int WA[101][10]{};

		char str[20];

		while (gets(str) && str[0])
		{

			sscanf(str, "%d%d%d%c%c", &id, &problem, &time, &temp, &L);

			data[id].id = id;

			if (AC[id][problem])
				continue;
			else if (L == 'C')
			{
				AC[id][problem] = true;

				data[id].penalty_time += time + WA[id][problem] * 20;
				data[id].AC_num++;
			}
			else if (L == 'I')
				WA[id][problem]++;
		}

		//bubble sort
		for (int i = 1; i < 101; i++)
			for (int j = 1; j < 101-i; j++)
			{
				if (!data[j+1].id)
					continue;

				if (data[j].AC_num == data[j+1].AC_num)
				{
					if (data[j].penalty_time == data[j+1].penalty_time)
					{
						if (data[j].id>data[j+1].id)
							swap(data[j], data[j+1]);
					}
					else if (data[j].penalty_time>data[j+1].penalty_time)
						swap(data[j], data[j+1]);
				}
				else if (data[j].AC_num < data[j+1].AC_num)
					swap(data[j], data[j+1]);
	
			}

		for (int i = 0; i<101; i++)
		{
			if (data[i].id)
			printf("%d %d %d\n", data[i].id, data[i].AC_num, data[i].penalty_time);

		}
	}

	return 0;
}
