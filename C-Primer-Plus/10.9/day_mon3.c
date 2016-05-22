/* day_mon3.c -- 使用指针符号 */
#include <stdio.h>
#define MONTHS 12

int main(int argc, char const *argv[])
{
	int days[MONTHS] = {31,28,31,30,31,30,31,31,30,31,30,31};
	int index;

	/*
		此处,days 是数组首元素的地址；days + index 是元素days[index] 的地址；
		*(days + index) 是这个元素的值，与days[index]等价

		days + 2 == &days[2]
		*(days + index) == days[index]

		*(days + 2) days的第三个元素的值
		* days + 2 第一个元素的值和2相加
	 */
	for (index = 0; index < MONTHS; index++)
	{
		printf("Month %2d has %d days.\n",index+1,*(days + index));
		// days[index] == *(days + index)
	}

	return 0;
}
