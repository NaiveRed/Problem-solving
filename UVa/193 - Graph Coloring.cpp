#include<cstdio>
#include<list>
#include<algorithm>

std::list<int> adjList[101];
std::list<int> black;
int vertex;//the number of points
int max;//the number of black points
int optima[100];//the ans
bool color[101];//false is white,true is black

void backtracking(int point);
int main()
{
	int Case;

	scanf("%d", &Case);
	
	while (Case--)
	{
		int  e;//edge
		scanf("%d%d", &vertex, &e);
		
		while (e--)
		{
			int a, b;
			scanf("%d%d", &a, &b);
			adjList[a].push_back(b);
			adjList[b].push_back(a);
		}

		backtracking(1);

		printf("%d\n", max);
		for (int i = 0; i < max - 1; i++)
			printf("%d ", optima[i]);
		printf("%d\n", optima[max - 1]);

		//init
		max = 0;
		for (int i = 1; i <= vertex; i++)
			adjList[i].clear();

	}

	return 0;
}
void backtracking(int point)
{

	if (point > vertex)
	{
		int temp = black.size();
		if (temp > max)
		{
			int i = 0;
			for (int n : black)
				optima[i++] = n;
			max = temp;
		}

	}
	else
	{
		bool isBlack = true;
		for (int n : adjList[point])
			if (color[n])
				isBlack = false;

		if (isBlack)
		{
			//���I���¦⪺���p�U�~�򰵻��j
			color[point] = true;
			black.push_back(point);
			
			backtracking(point+1);

			//�������I���զ�
			color[point] = false;
			black.pop_back();
		}

		//���I���զ⪺���p�U�����j
		backtracking(point + 1);
	}

}