/* divide.c -- 我们所知的除法 */
#include <stdio.h>


int main(int argc, char const *argv[])
{
	/*
		注意，没有把整数除法运算的结果四舍五入到最近的整数，而是进行截尾，即舍弃整个小数部分
		C99 要求使用趋零截尾
	 */
	printf("integer division: 5/4 is %d \n", 5/4);
	printf("integer division: 6/3 is %d \n", 6/3);
	printf("integer division: 7/4 is %d \n", 7/4);
	printf("floating division: 7/4 is %1.2f \n", 7.0/4);
	printf("mixed division: 7/4 is %1.2f \n", 7.0/4);
	return 0;
}
