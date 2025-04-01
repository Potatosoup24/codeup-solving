#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


//파라미터가 소수이면 1, 아니면 0을 리턴하는 함수
int isPrimeNumber(int m)
{
	if (m < 2) return 0; // 2보다 작은 경우 소수가 아님
	if (m == 2) return 1; // 2는 소수
	if (m % 2 == 0) return 0; // 2가 아닌짝수는 소수가 아님
	//짝수로 나누어 떨어지는 것들은 2로도 반드시 나누어 떨어짐->홀수만 고려해도 됨!!

	for (int i = 3; i * i <= m; i += 2) {
		if (m % i == 0) { //소수가 아님
			return 0;  //소수가 아닐 때는 0을 반환
		}
	}
	return 1; //소수일 때는 1을 반환
}

struct product {
	int num1;
	int num2;
}Product;

struct product* product_primes(int n) 
{
	static struct product K; //static을 사용하여 함수가 종료된 후에도 
	//변수의 값이 남아있도록 한다
	for (int i = 2; i <= n-1; i++) //i<-2~n-1
	{
		if (n%i==0) //n의 약수이고,
		{
			if (isPrimeNumber(i))//소수이고
			{
				if (isPrimeNumber(n / i)) // n/i 가 소수이면
				{ 
					K.num1 = i;
					K.num2 = n / i;
					return &K;
				}
			}
		}
	}
	return NULL;
}

int main(void) {
	int Num;
	scanf("%d", &Num);
	struct product* result = product_primes(Num);
	if (result == NULL) {
		printf("wrong number");
	}
	else {
		printf("%d %d",((result->num1) > (result->num2)) ? result->num2 : result->num1, ((result->num1) > (result->num2)) ? result->num1 : result->num2);
	}
	return 0;
}
