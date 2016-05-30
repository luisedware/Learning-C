/* addemup.c -- 4 种类型的语句 */
#include <stdio.h>

/* 求出前20个整数的和 */
int main(int argc, char const *argv[])
{
	int count, sum; /* 声明语句 */

	count = 0;	/* 赋值语句 */
	sum = 0;	/* 赋值语句 s*/
	while(count++ < 20 ){	/* 结构化语句 */
		sum = sum + count;
	}
	/* 空语句 */
	printf("sum = %d \n",sum); /* 函数语句 */

	/* 符合语句 */
	while(years < 100){
		wisdom = wisdom * 1.05;
		printf("%d %d\n",years, wisdom);
		years = years + 1;
	}

	return 0;
}
