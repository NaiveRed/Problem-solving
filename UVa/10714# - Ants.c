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
				if (place > (length - place))//�@�����ƪ��̵u�ɶ����k
					place = (length - place);
				if (temp < (length - temp))//�@�����ƪ��̪��ɶ����k
					temp = (length - temp);

				if (place > min)//�������ƨ������ɶ�(�̵u)=�@���ϥγ̵u�ɶ����k��O�̤[��
					min = place;
				if (temp > max)//�������ƨ������ɶ�(�̵u)=�@���ϥγ̪��ɶ����k��O�̤[��
					max = temp;
			}
			printf("%u %u\n", min, max);

			set--;
		}
	}
	return 0;
}