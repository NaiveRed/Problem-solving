/*
參考:
http://acm.nudt.edu.cn/~twcourse/PrimeNumberGeneration.html
http://www.csie.ntnu.edu.tw/~u91029/Prime.html#3
*/
#include<cmath>//sqrt()
#define N 20000000

int prime[N];

int notPrime[N]{true, true};
int sieve[N]{true, true};//功用同notPrime

void eratosthenes();//Sieve of Eratosthenes
void linear_sieve();//線性時間篩法
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
		大於sqrt()的，會在小於sqrt()時的notPrime[i]倍數劃到 ex. sqrt(10)=3...  10=2*5=5*2  5>sqrt(10)
		一個合數 x ，必定有一個小於等於 sqrt(x) 的質因數。所有小於等於 sqrt(x) 的質數，刪掉這些質數的倍數，就能刪掉所有合數了。
		*/
	{
		if (!notPrime[i])
		{
			for (int k = (N - 1) / i; k >= i; k--)//k為倍率，k小於i的在前面就已經做過了，ex.3*2(k)，在2*3(k)時就有了，所以最後到3*3(k)
				if (!notPrime[k])
					//如果倍率已經判斷過了，代表k*i也劃過，ex. 6*3，此時6已經在2的時候被劃掉了，而6*3=(2*3)*3=2*9，所以也被劃掉了
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
	//一邊輸入質數表，一邊刪掉每個數的質數倍，如此每個合數就只讀取一次!
	int count(0);
	for (int i = 2; i < N; i++)
	{
		if (!sieve[i])
			prime[count++] = i;

		for (int j = 0; prime[j] * i < N; j++)
		{
			sieve[prime[j] * i] = true;
			if (!(i%prime[j]))
				//如果在 i 等於質數，則會在目前質數表最後一個停下;
				//如果 i 為合數，那後面的prime[j]*i可以在之後拜訪到  ex.2(prime)*4 下一個是 3(prime)*4 = 12 ，在 2(prime)*6 的時候會拜訪到
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