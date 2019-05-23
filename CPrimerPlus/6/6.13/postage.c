/* postage.c -- 类邮资费率 */
#include <stdio.h>

int main(int argc, char const *argv[])
{
	const int FIRST_OZ = 37;
	const int NEXT_OZ = 23;
	int ounces, cost;
	printf(" ounces cost\n");

	/*
		第一个表达式中的逗号使 ounces 和 cost 的值都进行了初始化。
		逗号的第二次出现使每次循环中 ounces	增加 1，cost 增加23
	 */
	for (ounces = 1, cost = FIRST_OZ; ounces <= 16; ounces++, cost+= NEXT_OZ)
	{
		printf("%5d $%4.2f \n",ounces,cost/100.0);
	}

	return 0;
}
