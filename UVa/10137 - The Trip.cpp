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
		
		int n(sum % student);//因為無法除盡，需要有人多給的人數
		printf("%d,%d\n", avg, n);
		std::sort(expense, expense + student, [](int a, int b){return a > b; });

		int diff(0);

		for (int i = 0; i < n; i++)
			diff += abs(expense[i] - (avg + 1));//1為多付的，有可能是少給的人補給-1，也可能是多給的人要拿回來的錢-1
			
		for (int i = n; i < student; i++)
			diff += abs(avg - expense[i]);
			
		printf("$%.2lf\n", diff / 200.0);//剛剛計算有重複了給和拿的數量，需除以2 (p.s 多付的也會重複(補給和拿回來)，
	}
	return 0;
}
