#include<stdio.h>

int swap(int train[], int length, int count);//�p��洫�X��

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

	if (length < 2)//����׳ѤU����G�N����洫�A�Ǧ^�洫�X��
		return count;

	for (i = 0; i<length - 1; i++)

		if (train[i]>train[i + 1])//�۾F�⨮�[��j�p
		{
		temp = train[i + 1];
		train[i + 1] = train[i];
		train[i] = temp;
		count++;
		}
	length--;//�C���]���@���A�̫�@�`���[�N���ΦA��A�ҥH���״�@

	return swap(train, length, count);

}