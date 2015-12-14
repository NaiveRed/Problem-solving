#include<stdio.h>
#define N 10000

int num[N];

void Insertion_sort(int n, int index);//插入排序法
int main(){

	int n,index=0;
	while (scanf("%d", &n) != EOF)
	{
		Insertion_sort(n, index);//index指向為未排序的
		printf("%d\n", index+1 & 1 ? num[index / 2] : (num[index / 2] + num[index / 2 + 1]) / 2);//取中間數
		index++;
	}

	return 0;
}
void Insertion_sort(int n, int index){

	int i;
	for (i = index; i&&n < num[i-1]; i--)//由右到左，如果n>num[i-1]，就插到前面(num[i] = n)，num[i]原本的值已經在向右移的時候存進上一個了
		num[i] = num[i - 1];//向右移
	num[i] = n;//插入
}