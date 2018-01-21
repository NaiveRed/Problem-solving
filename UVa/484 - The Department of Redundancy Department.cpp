#include <cstdio>
#include <unordered_map>

int main()
{
	std::unordered_map<int, int> m;

	int n, order[10000], count = 0;
	while (scanf("%d", &n) != EOF)
	{
		if (!m.count(n))
			order[count++] = n;
		m[n]++;
	}

	for (int i = 0; i < count; i++)
		printf("%d %d\n", order[i], m[order[i]]);

	return 0;
}