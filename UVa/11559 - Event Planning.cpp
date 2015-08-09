#include<cstdio>
#include<climits>
int main()
{
	int people, money, hotel, day;

	while (scanf("%d%d%d%d", &people, &money, &hotel, &day) == 4)
	{
		int sum(INT_MAX);
		bool isOk(false);
		while (hotel--)
		{
			bool enough(false);
			int price;

			scanf("%d", &price);

			for (int i = 0; i < day; i++)
			{
				int room;

				scanf("%d", &room);

				enough = room >= people ? true : enough;
			}

			if (enough && (price*people) <= money)
			{
				sum = sum>price*people ? price*people : sum;

				isOk = true;
			}
		}

		if (isOk)
			printf("%d\n", sum);
		else puts("stay home");
	}
	return 0;
}