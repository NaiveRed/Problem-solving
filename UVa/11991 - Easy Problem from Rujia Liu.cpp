#include<cstdio>
#include<vector>

using namespace std;

vector<int>data[1000000];

int main()
{
	int length, m;

	while (scanf("%d%d", &length, &m) != EOF)
	{
		unsigned int key,offset;
		for (offset = 1; offset <= length; offset++)
		{
			scanf("%u", &key);
			data[key].push_back(offset);
		}

		for (int i = 0; i < m; i++)
		{
			unsigned int times;
			scanf("%d%d", &times, &key);
			if (data[key].empty() || data[key].size() < times)
				printf("0\n");
			else printf("%d\n", data[key][times - 1]);
		
		}

	}

	return 0;
}