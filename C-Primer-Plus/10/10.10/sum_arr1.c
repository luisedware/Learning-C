/* sum_arr1.c -- 对一个数组的所有元素求和 */
/* 如果不能使用%zd，请使用%u或%lu */
#include <stdio.h>
#define SIZE 10
/*
	函数sum()使用一个指针参量来确定数组的开始点，使用一个整数参量来指明数组
	的元素个数，但是这并不是向函数传递数组信息的唯一方法。
 */
int sum(int array[], int n);

int main(int argc, char const *argv[])
{
	/*
		请注意 marbles 的大小为40节。的确如此，因为 marbles 包含 10 个 int 类型的数
		每个数占4个字节，因此总共占用 40 个字节。

		但是 array 的大小只有 8 个字节，这是因为 array 本身并不是一个数组，
		它是一个指向 marbles 的首元素的指针

		C 中数组和指针之间的关系允许您在数组符号中使用指针 array;
	 */
	int marbles[SIZE] = {20,10,5,39,4,16,19,26,31,20};
	long answer;
	answer = sum(marbles,SIZE);
	printf("The total number of marbles is %ld.",answer);
	printf("The size of marbles is %zd bytes.\n", sizeof marbles);

	return 0;
}

int sum(int array[], int n){
	int i;
	int total = 0;

	for (i = 0; i < n; i++)
	{
		total += array[i];
	}

	printf("The size of array is %zd bytes.\n", sizeof array);

	return total;
}
