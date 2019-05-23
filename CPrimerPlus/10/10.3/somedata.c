/* some_data.c -- 部分初始化的数组 */
#include <stdio.h>
#define SIZE 4

int main(int argc, char const *argv[])
{
	int some_data[SIZE] = {1492,1066};
	int i;
	printf("%2s%14s\n",
		"i","some_data[i]");

	/* 当数值数目少于数组元素数目时，多余的数组元素被初始化为0。也就是说，如果不初始化数组
	，数组元素和未初始化的普通变量一样，其中存储的是无用的数值；但是如何部分初始化数组，未初
	始化的元素则被设置为0 */
	for (i = 0; i < SIZE; i++)
	{
		printf("%2d%14d\n",i,some_data[i]);
	}
	return 0;
}
