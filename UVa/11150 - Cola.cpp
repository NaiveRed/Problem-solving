#include<cstdio>

int main()
{
	int bottles;

	while (scanf("%d", &bottles) != EOF)
	{
		/*
		最後剩3個以上:繼續換
		剩2個:借一個空瓶繼續換->換1個，喝完剩1個
		剩1個:停止

		可發現最後都會剩下一個，所以最多只能跟人借1個
		*/

		int sum=bottles;
		bottles++;//都先借1個空瓶
		
		while (bottles >= 3)
		{
			sum += bottles / 3;
			bottles = bottles / 3 + bottles % 3;
		}

		printf("%d\n",sum);

	}

	return 0;
}