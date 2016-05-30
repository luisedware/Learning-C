/* day_mon2.c -- 让编译器计算元素个数  */
#include <stdio.h>

int main(int argc, char const *argv[])
{
	/* 当使用空的方括号对数组进行初始化时，编译器会根据列表中的数值数目来确定数组的大小 */
	const int days[] = {31,28,31,30,31,30,31,31,30,31,30,31};
	int index;

	/* 运算符 sizeof 给出其后的对象或类型的大小。因此 sizeof days 是整个数组的大小（以字节为单位）
	sizeof days[0] 是一个元素的大小（以字节为单位）。整个数组的大小除以单个元素的大小就是数组元素的数目 */
	for (index = 0; index < sizeof days / sizeof days[0]; index++)
	{
		printf("Month %2d has %d days.\n",index + 1,days[index]);
	}

	return 0;
}
