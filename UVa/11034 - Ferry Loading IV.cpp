#include<cstdio>
#include<queue>

int main()
{
	int Case;
	scanf("%d", &Case);

	while (Case--)
	{
		int ferry_length, car;
		scanf("%d%d", &ferry_length, &car);
		getchar();
		ferry_length *= 100;

		std::queue<int> left, right;
		while (car--)
		{
			char str[10];
			int length;
			scanf("%d%s", &length, str);

			if (str[0] == 'l')
				left.push(length);
			else
				right.push(length);
		}

		int times(0), current(0);
		bool flag(true);

		while (!left.empty() || !right.empty())
		{
			if (flag)
			{
				while (!left.empty())
				{
					if (left.front() + current <= ferry_length)
						current += left.front(), left.pop();
					else break;
				}
				
				flag = false;
		
			}
			else
			{
				while (!right.empty())
				{
					if (right.front() + current <= ferry_length)
						current += right.front(), right.pop();
					else break;
				}

				flag = true;
		
			}

			times++;
			current = 0;
		}

		printf("%d\n", times);

	}

	return 0;
}
