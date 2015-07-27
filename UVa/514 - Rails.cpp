#include<cstdio>
#include<stack>
#define N 1001

int main()
{
	int n, car[N] = { 0 };
	std::stack<int> station;

	while (scanf("%d", &n) && n)
	{

		while (scanf("%d", &car[1]) && car[1])
		{
			for (int i = 2; i <= n; i++)
				scanf("%d", &car[i]);

			int target(1), index(1);
			bool ans(true);

			while (index <= n)
			{
				if (target < car[index])//�p�G�ثe�����[�p����ƦC�����ǡA�N����istack��
					station.push(target++);
				else if (target == car[index])//�۵����ܡA���[�N�����L�h�F
				{
					target++;
					index++;
				}
				else 
				{	
					if (station.top() != car[index])//�J���۵��]���p��A���ѤU���ާ@�N�Opop�Xstack�������[�F
					{
						ans = false;
						break;
					}

					station.pop();
					index++;
				}
			}
			
			printf("%s\n", ans ? "Yes" : "No");
		}

		
		for (int i = 0; i <= n; i++)
			car[i] = 0;

		puts("");
	}

	return 0;
}