/* sum_arr2.c -- 对一个数组的所有元素求和 */
#include <stdio.h>
#define SIZE 10
/*
	函数sump传递两个指针，第一个指针指明数组的起始地址，第二个指针指明数组的
	结束地址。程序中没有使用索引来指示数组中的每个元素，而是直接修改指针本身，
	使指针依次指向各个数组元素
 */
int sump(int * start, int * end);

int main(int argc, char const *argv[])
{
	int marbles[SIZE] = {20,10,5,39,4,16,19,26,31,20};
	long answer;

	answer = sump(marbles,marbles + SIZE);
	printf("The total number of marbles is %ld.\n", answer);

	return 0;
}

/* 使用指针算术 */
int sump(int * start, int * end){
	int total = 0;
	while(start < end){
		total += *(start++);
		// 这两行代码可以缩写成为：*start++;
		// 为了清晰可见，应该使用：*(start++)
	}

	return total;
}
