#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void ascending(int* ptr,int* ptr2, int size);

int main(void) {
	int count_num;
	int index_num[256];
	int gas[256];
	scanf("%d", &count_num);
	for (int i = 0; i < count_num; i++) {
		scanf("%d %d",index_num + i, gas + i);
	}

	ascending(index_num, gas,count_num);

	for (int i = 0; i < count_num; i++) {
		printf("%d %d\n", index_num[i], gas[i]);
	}
	return 0;
}

void ascending(int* ptr,int* ptr2, int size) 
{
	for (int i = 0; i < size - 1; i++) 
	{
		for (int j = 0; j < size - i - 1; j++) 
		{
			if (ptr[j] > ptr[j + 1]) 
			{
				int temp = ptr[j];
				ptr[j] = ptr[j + 1];
				ptr[j + 1] = temp;

				int temp2 = ptr2[j];
				ptr2[j] = ptr2[j + 1];
				ptr2[j+1] = temp2;
			}
		}
	}
}
/*
3
2 10
3 20
1 30 //이렇게 입력하면

1 30
2 10
3 20 //이렇게 정렬해주는 프로그램

<입력>
첫째 줄에 입체기동장치의 갯수 n이 입력된다. (1 <= n <= 100)
둘째 줄부터 n+1째 줄까지 각 줄에 입체기동장치의 식별번호 a와 가스 보유량 b가 주어진다.
a는 중복 될 수 없지만 b는 중복될 수 있다. (1 <= a <= 100), (0 <= b <= 10,000)
====================================================================================
<출력>
첫째 줄부터 n번째 줄까지 각 줄에 식별번호를 오름차순으로 정렬해 가스 보유량과 같이 출력한다.
*/
