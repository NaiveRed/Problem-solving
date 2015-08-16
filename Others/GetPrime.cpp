/*
�Ѧ�:
http://acm.nudt.edu.cn/~twcourse/PrimeNumberGeneration.html
http://www.csie.ntnu.edu.tw/~u91029/Prime.html#3
*/
#include<cmath>//sqrt()
#define N 20000000

int prime[N];

int notPrime[N]{true, true};
int sieve[N]{true, true};//�\�ΦPnotPrime

void eratosthenes();//Sieve of Eratosthenes
void linear_sieve();//�u�ʮɶ��z�k
void easy_getPrime();
int main()
{

	//eratosthenes();
	//linear_sieve();
	//easy_getPrime();

	return 0;
}
void eratosthenes()
{
	int _sqrt(sqrt(N - 1));

	for (int i = 2; i <= _sqrt; i++)
		/*
		�j��sqrt()���A�|�b�p��sqrt()�ɪ�notPrime[i]���ƹ��� ex. sqrt(10)=3...  10=2*5=5*2  5>sqrt(10)
		�@�ӦX�� x �A���w���@�Ӥp�󵥩� sqrt(x) ����]�ơC�Ҧ��p�󵥩� sqrt(x) ����ơA�R���o�ǽ�ƪ����ơA�N��R���Ҧ��X�ƤF�C
		*/
	{
		if (!notPrime[i])
		{
			for (int k = (N - 1) / i; k >= i; k--)//k�����v�Ak�p��i���b�e���N�w�g���L�F�Aex.3*2(k)�A�b2*3(k)�ɴN���F�A�ҥH�̫��3*3(k)
				if (!notPrime[k])
					//�p�G���v�w�g�P�_�L�F�A�N��k*i�]���L�Aex. 6*3�A����6�w�g�b2���ɭԳQ�����F�A��6*3=(2*3)*3=2*9�A�ҥH�]�Q�����F
					notPrime[k*i] = true;
		}

	}

	int count(0);
	for (int i = 0; i < N; i++)
		if (!notPrime[i])
			prime[count++] = i;

}
void linear_sieve()
{
	//�@���J��ƪ�A�@��R���C�Ӽƪ���ƭ��A�p���C�ӦX�ƴN�uŪ���@��!
	int count(0);
	for (int i = 2; i < N; i++)
	{
		if (!sieve[i])
			prime[count++] = i;

		for (int j = 0; prime[j] * i < N; j++)
		{
			sieve[prime[j] * i] = true;
			if (!(i%prime[j]))
				//�p�G�b i �����ơA�h�|�b�ثe��ƪ�̫�@�Ӱ��U;
				//�p�G i ���X�ơA���᭱��prime[j]*i�i�H�b������X��  ex.2(prime)*4 �U�@�ӬO 3(prime)*4 = 12 �A�b 2(prime)*6 ���ɭԷ|���X��
				break;
		}
	}

}
void easy_getPrime()
{

	int count(0);

	for (int i = 2; i < N; i++)
	{
		if (!notPrime[i])
		{
			prime[count++] = i;

			for (int j = i + i; j < N; j += i)
				notPrime[j] = true;
		}

	}

}