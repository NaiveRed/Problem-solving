#include<cstdio>
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))

//Maximum Product Subarray
//�`�Noverflow �M set �u�X�{0�����p(ex: 2 0 0)
int main()
{
	int set, Case(0);

	while (scanf("%d", &set) != EOF)
	{
		int num[20]{};

		for (int i = 0; i < set; i++)
			scanf("%d", &num[i]);

		//include empty set is zero
		//max_sub,min_sub ���Y�����s���`�M(1��K���k)�Amax_total���䤤�s��̤j���`�M
		long long max_sub(1), min_sub(1), max_total(0);

		if (set != 1)
			for (int n : num)
			{
			//n��0�ɡAsubarray�����s�}�l
			if (!n)
			{
				min_sub = max_sub = 1;
				continue;
			}

			long long temp = max_sub;

			//��"max���Wn��"�M"n"(�N�qn�}�l��subarray)���Ӥj�A�A�h�B�z�p�Gn���t�A���Wmin_sub�i�ର��j
			max_sub = MAX(MAX(max_sub*n, n), min_sub*n);

			//�@�ˬ�"���Wn��"�M"n"(�N�qn�}�l��subarray)���Ӥp�A�A�h�B�z�p�Gn���t�A���W��max_sub�i�ର��p
			min_sub = MIN(MIN(min_sub*n, n), temp*n);

			max_total = MAX(max_sub, max_total);
			}
		else
			max_total = num[0] < 0 ? 0 : num[0];

		printf("Case #%d: The maximum product is %lld.\n\n", ++Case, max_total);
	}

	return 0;
}