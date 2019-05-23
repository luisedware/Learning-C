/* sweetie1.c -- 一个计数循环 */
#include <stdio.h>

int main(int argc, char const *argv[])
{
	const int NUMBER = 22;
	int count = 1;
	/*
		1.必须初始化一个计数器
		2.计数器与某个有限的值进行比较
		3.每次执行循环，计数器的值都要递增
	 */
	while(count <= NUMBER){
		printf("Be my Valentine!\n");
		count++;
	}

	return 0;
}
