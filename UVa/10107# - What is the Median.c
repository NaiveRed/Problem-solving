#include<stdio.h>
#define N 10000

int num[N];

void Insertion_sort(int n, int index);//���J�ƧǪk
int main(){

	int n,index=0;
	while (scanf("%d", &n) != EOF)
	{
		Insertion_sort(n, index);//index���V�����ƧǪ�
		printf("%d\n", index+1 & 1 ? num[index / 2] : (num[index / 2] + num[index / 2 + 1]) / 2);//��������
		index++;
	}

	return 0;
}
void Insertion_sort(int n, int index){

	int i;
	for (i = index; i&&n < num[i-1]; i--)//�ѥk�쥪�A�p�Gn>num[i-1]�A�N����e��(num[i] = n)�Anum[i]�쥻���Ȥw�g�b�V�k�����ɭԦs�i�W�@�ӤF
		num[i] = num[i - 1];//�V�k��
	num[i] = n;//���J
}