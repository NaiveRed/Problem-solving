#include<cstdio>
#include<stack>
#include<vector>
#define N 1000
using namespace std;

vector<int> v[N];
int path[N];
bool isVisit[N];
bool backtracking(int n, int count);
int main()
{

	int n, i, j;

	while (scanf("%d", &n) != EOF)
	{
		for (i = 0; i <= n; i++)
		{
			isVisit[i] = false;
			v[i].clear();
		}

		while (scanf("%d%d", &i, &j) == 2)
		{
			v[i].push_back(j);
			v[j].push_back(i);
		}
		getchar();

		path[0] = 1;
		isVisit[1] = true;
		if (!backtracking(n, 1))
			puts("N");
	}

	return 0;
}
bool backtracking(int n, int count)
{
	static int first;
	int i, j;

	if (count == n)
	{
		int size = v[path[n - 1]].size();
		for (i = 0; i < size; i++)
			if (v[path[n - 1]][i] == path[0])
			{
				for (int j = 0; j < n; j++)
					printf("%d ", path[j]);
				printf("%d\n", path[0]);
				return true;
			}

		return false;
	}

	int size = v[path[count - 1]].size();
	for (i = 0; i < size; i++)
	{
		int next = v[path[count - 1]][i];
		if (!isVisit[next])
		{
			isVisit[next] = true;

			path[count] = next;
			if (backtracking(n, count + 1))
				return true;

			isVisit[next] = false;
		}
	}

	return false;
}