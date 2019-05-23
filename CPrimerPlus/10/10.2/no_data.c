/* no_data.c -- 未经初始化的数组 */
#include <stdio.h>
#define SIZE 4

int main(int argc, char const *argv[])
{
	int no_data[SIZE]; /* 未经初始化的数组 */
	int i;

	printf("%2s%14s\n",
		"i","no_data[i]");

	/* 如果没有进行初始化，一些存储类的变量和数组会把它们的存储单元设置为0 */
	for (i = 0; i < SIZE; i++)
	{
		printf("%2d%14d\n",i,no_data[i]);
	}

	return 0;
}
