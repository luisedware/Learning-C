/* order.c -- 指针运算的优先级 */
#include <stdio.h>
int data[2] = {100,200};
int moredata[2] = {300,400};

int main(int argc, char const *argv[])
{
	int * p1, * p2, * p3;
	p1 = p2 = data;
	p3 = moredata;
	printf("  *p1 = %d, *p2 = %d,     *p3 = %d\n",
			*p1,*p2,*p3);
	printf("*p1++ = %d,*++p2 = %d,(*p3)++ = %d\n",
			*p1++,*++p2,(*p3)++);
	printf("  *p1 = %d, *p2 = %d, *p3 = %d\n",
			*p1,*p2,*p3);
	/*
		在 C 中，两个表达式 ar[i] 和 *(ar+i) 的意义是等价。而且不管 ar 是一
		个数组名还是一个指针变量，这两个表达式都可以工作。

	一元运算符 * 和 ++ 具有相等的优先级，但它在结合时是从右向左进行的。这就意味
	着 ++ 应用于 p1 而不是 *p1，也就是说，指针自增1;
	 */
	return 0;
}
