/* 判断质数 */
#include<stdio.h>
#include<math.h>

int main(int argc, char const *argv[])
{
	int Num,i;

	scanf("%d",&Num);

	if(Num == 2){
		printf("Yes\n");
		return 0;
	}

	if(Num % 2 == 0){
		printf("NO\n");
		return 0;
	}

	for (int i = 3; i <= sqrt(Num); i = i+2)
	{
		if(Num % i == 0){
			printf("NO\n");
			return 0;
		}
	}

	printf("YES\n");
	return 0;
}
