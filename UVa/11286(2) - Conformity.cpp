/*time: 0.177*/
#include<cstdio>
#include<algorithm>
#include<set>
#include<map>

using namespace std;
int main()
{
	int student;

	while (scanf("%d", &student) && student)
	{
		map<set<int>, int> lesson;
		int num[5];
		
		while (student--)
		{
			scanf("%d%d%d%d%d", &num[0], &num[1], &num[2], &num[3], &num[4]);
		
			set<int>temp{ num[0], num[1], num[2], num[3], num[4] };

			lesson[temp]++;
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