/* ptr_ops.c -- 指针操作 */
#include <stdio.h>

int main(int argc, char const *argv[])
{
	/* 声明一个整型数组 */
	int urn[5] = {100,200,300,400,500};

	/* 声明三个整型指针 */
	int *ptr1, *ptr2, *ptr3;

	ptr1 = urn;		// 把数组起始地址赋给指针
	ptr2 = &urn[2];	// 同上
					// 取得指针指向的值
					// 并且得到指针的地址
	/*
		赋值 -- 可以把一个地址赋给指针。通常使用数组名或地址运算符 & 来进行地址
		赋值。本例中，把数组urn的起始地址赋给 ptr1,该地址是编号为0x7fff5cf85be0
		的内存单元。变量ptr2得到的是数组第3个也即最后一个元素的地址
	 */

	printf("pointer value,dereferenced pointer, pointer address:\n");
	printf("ptr1 = %p, *ptr1 = %d, &ptr1 = %p\n",
			ptr1,*ptr1,&ptr1);
	/*
		求值或取值 -- 运算符*可取出指针指向地址中存储的数值
		因此，*ptr1 开始为 100,即存储在地址 0x7fff5b6a5be0 中的值
	 */
	/*
		取指针地址 -- 指针变量同其他变量一样具有地址和数值，使用运算符&可以得到
		存储指针本身的地址。本例中，ptr1 被存储在内存地址 0x7fff5d5c0bc8
	 */

	// 指针加法
	ptr3 = ptr1 + 4;
	printf("\nadding an int to a pointer:\n");
	printf("ptr1 + 4 = %p, *(ptr4 + 3) = %d\n",ptr1 + 4,*(ptr1 +3));
	/*
		将一个整数加给指针 -- 可以使用+运算符来把一个整数加给一个指针，或者把一个
		指针加给一个整数。
	 */

	ptr1++;	// 递增指针
	printf("\nvalues after ptr1++\n");
	printf("ptr1 = %p, *ptr1 = %d,&ptr1 = %p\n",
		ptr1,*ptr1,&ptr1);
	/*
		增加指针的值 -- 可以通过一般的加法或增量运算符来增加一个指针的值。对指向
		某数组元素的指针做增量运算，可以让指针指向该数组的下一个元素。
	 */

	ptr2--;	// 递减指针
	printf("\nvalues after --ptr2\n");
	printf("ptr2 = %p, *ptr2 = %d, &ptr2 = %p\n",
			ptr2,*ptr2,&ptr2);
	/*
		减少指针的值 -- ptr2 自减 1 之后，它将不再指向第三个元素，而是指向第二
		个数组元素。
	 */

	--ptr1;	// 恢复为初始值
	++ptr2; // 恢复为初始值
	printf("\nPointers reset to original values:\n");
	printf("ptr1 = %p,ptr2 = %p\n",ptr1,ptr2);

	// 一个指针减去另一个指针
	printf("\nsubtracting one pointer from another:\n");
	printf("ptr2 = %p,ptr1 = %p,ptr2 - ptr1 = %d\n",
		ptr2,ptr1,ptr2-ptr1);
	/*
		求差值 -- 可以求出两个指针间的差值，通常对分别指向同一个数组内两个元素的
		指针求差值，以求出元素之间的距离
	 */

	// 一个指针减去一个整数
	printf("\nsubtracting an int from a pointer:\n");
	printf("ptr3 = %p, ptr3 - 2 = %p, *ptr3 = %d\n",ptr3,ptr3-2,*ptr3);

	return 0;
}
