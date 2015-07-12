#include<cstdio>
#include<queue>

int main()
{
	std::queue<int> deck;
	int num;

	while (scanf("%d", &num) && num != 0)
	{

		bool first(true);
		for (int i = 1; i <= num; i++)
			deck.push(i);

		printf("Discarded cards:");
		while (deck.size() != 1)
		{
			if (!first)
				printf(",");
				
			printf(" %d", deck.front());

			deck.pop();

			deck.push(deck.front());

			deck.pop();

			first = false;
		}

		printf("\nRemaining card: %d\n", deck.back());
		
		deck.pop();
	}

	return 0;
}