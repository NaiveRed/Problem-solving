/*time: 0.102*/
#include<cstdio>
#include<algorithm>
#include<string>
#include<map>

using namespace std;
int main()
{
	int student;

	while (scanf("%d", &student) && student)
	{
		map<string, int> lesson;
		int num[5];
		char buf[25];

		while (student--)
		{
			scanf("%d%d%d%d%d", &num[0], &num[1], &num[2], &num[3], &num[4]);
			sort(num, num + 5);

			sprintf(buf, "%d%d%d%d%d", num[0], num[1], num[2], num[3], num[4]);
			lesson[buf]++;
		}

		int max(0), max_sum(0);

		for (auto p : lesson)
		{
			if (p.second > max)
				max = max_sum = p.second;
			else if (p.second == max)
				max_sum += max;
		}
		printf("%d\n", max_sum);
	}

	return 0;
}