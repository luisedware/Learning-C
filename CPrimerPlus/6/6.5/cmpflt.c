/* cmpflt.c -- 浮点数比较 */
#include <math.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
	const double ANSWER = 3.14159;
	double response;

	printf("what is the value of pi?\n");

	scanf("%lf",&response);

	/*
		在用户的答案和正确值的误差小于 0.0001 之前，这个循环反复地请求输入答案
	 */
	while(fabs(response - ANSWER) > 0.0001){
		printf("Try again!\n");
		scanf("%lf",&response);
	}

	printf("Close enought!\n");
	return 0;
}
