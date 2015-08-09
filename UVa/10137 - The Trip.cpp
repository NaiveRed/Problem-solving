#include<cstdio>
#include<algorithm>
#include<cmath>
#define N 1001

int main()
{
	int student;
	int expense[N]{0};

	while (scanf("%d", &student) && student)
	{
		int sum(0);

		for (int i = 0; i < student; i++)
		{
			int a, b;
			scanf("%d.%d", &a, &b);
			expense[i] = a * 100 + b;
			sum += expense[i];
		}

		int avg(sum / student);
		
		int n(sum % student);//�]���L�k���ɡA�ݭn���H�h�����H��
		printf("%d,%d\n", avg, n);
		std::sort(expense, expense + student, [](int a, int b){return a > b; });

		int diff(0);

		for (int i = 0; i < n; i++)
			diff += abs(expense[i] - (avg + 1));//1���h�I���A���i��O�ֵ����H�ɵ�-1�A�]�i��O�h�����H�n���^�Ӫ���-1
			
		for (int i = n; i < student; i++)
			diff += abs(avg - expense[i]);
			
		printf("$%.2lf\n", diff / 200.0);//���p�⦳���ƤF���M�����ƶq�A�ݰ��H2 (p.s �h�I���]�|����(�ɵ��M���^��)�A
	}
	return 0;
}
