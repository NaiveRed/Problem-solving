#include<stdio.h>

int main(){
	unsigned int set;

	while (scanf("%u", &set) != EOF)
	{
		unsigned int length, ant, place, max, min, temp;
		while (set)
		{
			max = 0; min = 0;
			scanf("%u %u", &length, &ant);

			for (; ant > 0; ant--){

				scanf("%u", &place);
				temp = place;
				if (place > (length - place))//一隻螞蟻的最短時間走法
					place = (length - place);
				if (temp < (length - temp))//一隻螞蟻的最長時間走法
					temp = (length - temp);

				if (place > min)//全部螞蟻走完的時間(最短)=一隻使用最短時間走法花費最久的
					min = place;
				if (temp > max)//全部螞蟻走完的時間(最短)=一隻使用最長時間走法花費最久的
					max = temp;
			}
			printf("%u %u\n", min, max);

			set--;
		}
	}
	return 0;
}