#include<cstdio>
#define N 10000

int num[N];

void Insertion_sort(int n, int index);//插入排序法
int main(){

	int n, index = 0;
	while (scanf("%d", &n) != EOF)
	{
		Insertion_sort(n, index);//index指向為未排序的
		printf("%d\n", index + 1 & 1 ? num[index / 2] : (num[index / 2] + num[index / 2 + 1]) / 2);//取中間數
		index++;
	}

	return 0;
}
void Insertion_sort(int n, int index){
	
	//小到大
	int i, right = index - 1, left = 0, mid;

	//binary search
	while (left <= right)
	{
		mid = (left + right) / 2;
		if (n < num[mid])
			right = mid - 1;
		else if (n > num[mid])
			left = mid + 1;
		else
			break;
	}

	for (i = index; i>left; i--)//從尾做到剛剛binary search找到的位置
		num[i] = num[i - 1];//向右移

	num[i] = n;//插入
}