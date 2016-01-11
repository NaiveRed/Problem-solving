/*
��n�γo�D�Ӵ��ո굲��deap
*/
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define PARENT(i) ((i)>>1)//i/2
#define SIZE_TO_IDX(size) ((size)+1)
#define N 1000001

typedef struct deap
{
	int *arr;
	int size;
	int max_size;

}Deap;

Deap* createDeap(int size);
bool deapIsEmpty(Deap* d);
bool InMaxHeap(int idx);//return false if in min heap
int correspondToMax(int size, int idx);//return the partner of min in max heap, size ���ثe��deap���d��
int correspondToMin(int idx);//return the partner of max in min heap
void insertMinHeap(Deap* d, int idx, int num);//utility function to insert in min heap
void insertMaxHeap(Deap* d, int idx, int num);//utility function to insert in max heap
bool insertDeap(Deap* d, int num);//return false if deap is full or didn't init
int popMinHeap(Deap* d);
int popMaxHeap(Deap* d);

int main()
{
	Deap *d = createDeap(N);

	int i, n;
	while (scanf("%d", &i) != EOF)
	{
		if (i == 1)
		{
			scanf("%d", &n);
			insertDeap(d, n);
		}
		else if (i == 2)
		{
			if (d->size == 1)
				printf("%d\n",popMinHeap(d));
			else 
				printf("%d\n", popMaxHeap(d));
		}
		else if (i == 3)
			printf("%d\n",popMinHeap(d));
	}

	return 0;
}
Deap* createDeap(int size)
{
	Deap* deap = (Deap*)malloc(sizeof*deap);
	deap->arr = (int*)calloc(size + 2, sizeof(int));//0,1���s��F��,1����
	deap->max_size = size;
	deap->size = 0;

	return deap;
}
bool InMaxHeap(int idx)
{
	while (idx > 3)
		idx /= 2;
	return idx == 3 ;
}
bool deapIsEmpty(Deap* d)
{
	return d->size ? false : true;
}
int correspondToMax(int size, int idx)
{
	/*
	log is base 2.
	x = (n + 2^((logn)-1))
	if x > �ثe����
	x /= 2
	*/
	if (idx == 2)
		return 2;
	int i;
	for (i = 2; i * 2 <= idx; i *= 2);
	i /= 2;
	if (idx + i > size)//�p�G��L�h��Max heap�w�W�X�d��N�n���H2
		return (idx + i) / 2;
	return idx + i;
}
int correspondToMin(int idx)
{
	/*
	log is base 2.
	f(n) = n - 2^((logn)-1)
	*/
	int i;
	for (i = 2; i * 2 <= idx; i *= 2);

	return idx - i / 2;
}
void insertMinHeap(Deap* d, int idx, int num)
{
	while (idx > 2 && num < d->arr[PARENT(idx)])//the root of min heap is 2
	{
		d->arr[idx] = d->arr[PARENT(idx)];
		idx = PARENT(idx);
	}

	d->arr[idx] = num;

}
void insertMaxHeap(Deap* d, int idx, int num)
{
	while (idx > 3 && num > d->arr[PARENT(idx)])//the root of max heap is 3
	{
		d->arr[idx] = d->arr[PARENT(idx)];
		idx = PARENT(idx);
	}

	d->arr[idx] = num;

}
bool insertDeap(Deap* d, int num)
{

	if (deapIsEmpty(d))
	{
		d->arr[2] = num;
		d->size++;
	}
	else
	{
		int idx = SIZE_TO_IDX(++d->size);
		int i;
		switch (InMaxHeap(idx))
		{
			//in max heap
		case true:
			i = correspondToMin(idx);
			/*
			����bmin heap(MinH)�̬۹������Ʀr
			(1)
			�p�GMinH�̪���num�j�A�N�洫�L�̡A�ç�s�����JMinH��
			(2)
			�p�GMinH�̪���num�p�A�N�������JMax Heap��
			*/
			if (num < d->arr[i])
			{
				d->arr[idx] = d->arr[i];
				insertMinHeap(d, i, num);
			}
			else
				insertMaxHeap(d, idx, num);
			break;
			//in min heap
		case false:
			i = correspondToMax(idx,idx);
			/*
			����bmax heap(MaxH)�̬۹������Ʀr
			(1)
			�p�GMaxH�̪���num�p�A�N�洫�L�̡A�ç�s�����JMaxH��
			(2)
			�p�GMaxH�̪���num�j�A�N�������JMin Heap��
			*/
			if (num > d->arr[i])
			{
				d->arr[idx] = d->arr[i];
				insertMaxHeap(d, i, num);
			}
			else
				insertMinHeap(d, idx, num);
		}
	}

	return true;
}
int popMinHeap(Deap* d)
{
	int min = d->arr[2];
	int temp = d->arr[SIZE_TO_IDX(d->size)];
	int size = SIZE_TO_IDX(--d->size);//�̫�@�Ӯ��ӭ���

	int p, c;//parent,child
	for (p = 2; p * 2 <= size; p = c)//min heap���Ĥ@��pop���F�A���s�վ�min heap
	{
		c = p * 2;
		if (c + 1 <= size)
			if (d->arr[c] > d->arr[c + 1])
				c++;
		d->arr[p] = d->arr[c];
	}

	
	int partner = correspondToMax(size,p);//�վ㧹�᪺�Ů�Apartner������max heap������m
	if (d->arr[partner] < temp)
	{
		/*
		��max heap�������j:
		�Nmin heap���Ů��Jmax partner���Ʀr
		�N���deap���̫�@�Ӥ������Jmax heap
		*/
		d->arr[p] = d->arr[partner];
		insertMaxHeap(d, partner, temp);
	}
	else
		insertMinHeap(d, p, temp);//�Nmin heap���Ů��J������̫�@��

	return min;
}
int popMaxHeap(Deap* d)
{
	int max = d->arr[3];
	int temp = d->arr[SIZE_TO_IDX(d->size)];
	int size = SIZE_TO_IDX(--d->size);//�̫�@�Ӯ��ӭ���

	int p, c;//parent,child
	for (p = 3; p * 2 <= size;)//max heap���Ĥ@��pop���F�A���s�վ�max heap
	{
		c = p * 2;
		if (c + 1 <= size)
			if (d->arr[c] < d->arr[c + 1])
				c++;
		d->arr[p] = d->arr[c];
		p = c;
	}

	int partner = correspondToMin(p);//�վ㧹�᪺�Ů�Apartner������min heap������m
	/*
	�]���qmax��L�hmin���i���٦��l�`�I
	�ҥH��partner�٦��S���l�`�I�A�����ܭn�A���P�_�A���j��
	*/
	if (partner * 2 <= size)
	{
		partner *= 2;
		if (partner + 1 <= size&&d->arr[partner] < d->arr[partner + 1])
			partner++;
	}

	if (d->arr[partner] > temp)
	{
		/*
		��min heap�������p:
		�Nmax heap���Ů��Jmin partner���Ʀr
		�N���deap���̫�@�Ӥ������Jmin heap
		*/
		d->arr[p] = d->arr[partner];
		insertMinHeap(d, partner, temp);
	}
	else
		insertMaxHeap(d, p, temp);//�Nmax heap���Ů��J������̫�@��

	return max;
}

