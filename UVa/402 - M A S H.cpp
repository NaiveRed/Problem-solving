#include<cstdio>
#define N 20

int Queue[51];

int input();
void next(int& flag, int people);
int main()
{

	int people,Case(0);

	while ((people = input()) != EOF)
	{
		Case++;
		
		int lucky = input();
		int card[N];

		//init
		for (int i = 1; i <= people; i++)
			*(Queue + i ) = i;
		for (int i = 0; i < N; i++)
			*(card + i) = input();

		int flag(1),p(people);
		//start to pick person
		for (int m : card)
		{
			if (p == lucky)//達到要求人數
				break;

			for (int times = p / m; times; times--)//每張卡片可以剔除掉的人
			{
				for (int i = 0; i < m - 1; i++)//當前的人也算進去，所以i < m-1
					next(flag, people);//下一個未被剔除的人

				Queue[flag] = 0;
				next(flag, people);
				p--;

				if (p == lucky)
					break;
			}

			//back to first
			flag = 0;
			next(flag, people);

		}

		printf("Selection #%d\n",Case);

		bool first(true);
		for (int i = 1; i <= people; i++)
			if (Queue[i])
			{
			if (first)
				first = false;
			else putchar(' ');

			printf("%d", Queue[i]);
			Queue[i] = 0;
			}
	
		putchar('\n');
		putchar('\n');
	}


	return 0;
}
int input()
{
	int num(0);
	char c;

	while ((c = getchar()) != ' '&&c != '\n')
	{
		if (c == EOF)
			return EOF;
		num = num * 10 + c - '0';
	}
	return num;
}
void next(int& flag, int people)
{
	for (int i = flag + 1; i <= people; i++)//超過people，就要重新開始下一張卡了
		if (Queue[i])
		{
		flag = i;
		break;
		}
}