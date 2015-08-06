#include<stdio.h>

int swap(int train[], int length, int count);//計算交換幾次

int main(){

	int set;

	while (scanf("%d", &set) != EOF)
	{
		int length, train[50] = { 0 };



		for (; set > 0; set--){

			scanf("%d", &length);

			int i, count = 0;

			for (i = 0; i < length; i++)
				scanf("%d", &train[i]);

			count = swap(train, length, count);

			printf("Optimal train swapping takes %d swaps.\n", count);
		}
	}
	return 0;
}


int swap(int train[], int length, int count)
{
	int temp, i;

	if (length < 2)//當長度剩下不到二就停止交換，傳回交換幾次
		return count;

	for (i = 0; i<length - 1; i++)

		if (train[i]>train[i + 1])//相鄰兩車廂比大小
		{
		temp = train[i + 1];
		train[i + 1] = train[i];
		train[i] = temp;
		count++;
		}
	length--;//每次跑完一次，最後一節車廂就不用再算，所以長度減一

	return swap(train, length, count);

}