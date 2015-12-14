#include<cstdio>
#define N 10000

int num[N];

void Insertion_sort(int n, int index);//���J�ƧǪk
int main(){

	int n, index = 0;
	while (scanf("%d", &n) != EOF)
	{
		Insertion_sort(n, index);//index���V�����ƧǪ�
		printf("%d\n", index + 1 & 1 ? num[index / 2] : (num[index / 2] + num[index / 2 + 1]) / 2);//��������
		index++;
	}

	return 0;
}
void Insertion_sort(int n, int index){
	
	//�p��j
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

	for (i = index; i>left; i--)//�q��������binary search��쪺��m
		num[i] = num[i - 1];//�V�k��

	num[i] = n;//���J
}